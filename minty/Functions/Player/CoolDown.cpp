#include "CoolDown.h"

namespace cheat {
    static bool Skill_CheckCd_Hook(void/*Skill*/* __this, app::MethodInfo* method);
    static bool Skill_CheckCost_Hook(void/*Skill*/* __this, app::MethodInfo* method);
   // static bool Skill_CheckState_Hook(void/*Skill*/* __this, app::MethodInfo* method);
    CoolDown::CoolDown() {
        f_Enabled = config::getValue("functions:CoolDown", "enabled", false);

        f_Hotkey = Hotkey("functions:CoolDown");

        HookManager::install(app::Skill_CheckCd, Skill_CheckCd_Hook);
        HookManager::install(app::Skill_CheckCost, Skill_CheckCost_Hook);
      //  HookManager::install(app::Skill_CheckState, Skill_CheckState_Hook);


    }

    CoolDown& CoolDown::getInstance() {
        static CoolDown instance;
        return instance;
    }

    void CoolDown::GUI() {
        if (ConfigCheckbox(_("CoolDown"), f_Enabled, _("CoolDown"))) {
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
            ImGui::Text(_("CoolDown"));
    }

    std::string CoolDown::getModule() {
        return _("Player");
    }



    bool Skill_CheckCd_Hook(void/*Skill*/* __this, app::MethodInfo* method) {
        auto& CoolDown = CoolDown::getInstance();
        if (CoolDown.f_Enabled) {
            return true;
        }
        else
           return CALL_ORIGIN(Skill_CheckCd_Hook, __this, method);
    
    }
    bool Skill_CheckCost_Hook(void/*Skill*/* __this, app::MethodInfo* method) {
        auto& CoolDown = CoolDown::getInstance();
        if (CoolDown.f_Enabled) {
            return true;
        }
        else
           return  CALL_ORIGIN(Skill_CheckCost_Hook, __this, method);

    }

    //bool Skill_CheckState_Hook(void/*Skill*/* __this, app::MethodInfo* method) {
    //    auto & CoolDown = CoolDown::getInstance();
    //    if (CoolDown.f_Enabled) {
    //        return true;
    //    }
    //    else
    //       return  CALL_ORIGIN(Skill_CheckState_Hook, __this, method);
    //}
}
