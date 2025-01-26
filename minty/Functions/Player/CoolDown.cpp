#include "CoolDown.h"

namespace cheat {
    static bool Skill_CheckCd_Hook(void/*Skill*/* __this, app::MethodInfo* method);
    static bool Skill_CheckCost_Hook(void/*Skill*/* __this, app::MethodInfo* method);
    CoolDown::CoolDown() {
        f_Enabled = config::getValue("functions:CoolDown", "enabled", false);

        f_Hotkey = Hotkey("functions:CoolDown");

        HookManager::install(app::Skill_CheckCd, Skill_CheckCd_Hook);
        HookManager::install(app::Skill_CheckCost, Skill_CheckCost_Hook);


    }

    CoolDown& CoolDown::getInstance() {
        static CoolDown instance;
        return instance;
    }

    void CoolDown::GUI() {
        if (ConfigCheckbox(_("CoolDown_TITLE"), f_Enabled, _("CoolDown_DESCRIPTION"))) {
            ImGui::Indent();
            f_Hotkey.Draw();
            ImGui::Unindent();
        }
    }

    void CoolDown::Outer() {
        if (f_Hotkey.IsPressed())
        {
            f_Enabled.setValue(!f_Enabled.getValue());
        }
    }

    void CoolDown::Status() {
        if (f_Enabled)
            ImGui::Text(_("CoolDown_TITLE"));
    }

    std::string CoolDown::getModule() {
        return _("MODULE_PLAYER");
    }

    //void VCHumanoidMove_NotifyLandVelocity_Hook(app::VCHumanoidMove* __this, app::Vector3 velocity,
    //    float reachMaxDownVelocityTime) {
    //    auto& CoolDown = CoolDown::getInstance();

    //    if (CoolDown.f_Enabled && -velocity.y > 13) {
    //        float randAdd = (float)(std::rand() % 1000) / 1000;
    //        velocity.y = -8 - randAdd;
    //        reachMaxDownVelocityTime = 0;
    //    }
    //    CALL_ORIGIN(VCHumanoidMove_NotifyLandVelocity_Hook, __this, velocity, reachMaxDownVelocityTime);
    //}

    bool Skill_CheckCd_Hook(void/*Skill*/* __this, app::MethodInfo* method) {
        auto& CoolDown = CoolDown::getInstance();
        if (CoolDown.f_Enabled) {
            return false;
        }
        else
           return CALL_ORIGIN(Skill_CheckCd_Hook, __this, method);
    
    }
    bool Skill_CheckCost_Hook(void/*Skill*/* __this, app::MethodInfo* method) {
        auto& CoolDown = CoolDown::getInstance();
        if (CoolDown.f_Enabled) {
            return false;
        }
        else
           return  CALL_ORIGIN(Skill_CheckCost_Hook, __this, method);

    }
}
