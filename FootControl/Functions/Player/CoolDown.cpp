#include "CoolDown.h"

namespace cheat {
    static bool Skill_CheckCd_Hook(void/*Skill*/* __this, app::MethodInfo* method);
    static bool Skill_CheckCost_Hook(void/*Skill*/* __this, app::MethodInfo* method);
    //static int32_t SC_SYNC_ULTIMATE_SP_CELL_CNT_get_UltimateSpCellCnt_Hook(void/*SC_SYNC_ULTIMATE_SP_CELL_CNT*/* __this,app:: MethodInfo* method);
   // static bool Skill_CheckState_Hook(void/*Skill*/* __this, app::MethodInfo* method);
    static float AbilitySystem_get_ultimateSp_Hook (void/*AbilitySystem*/* __this, app::MethodInfo* method);

    CoolDown::CoolDown() {
        f_Enabled = config::getValue("functions:CoolDown", "enabled", false);

        f_Hotkey = Hotkey("functions:CoolDown");

        HookManager::install(app::Skill_CheckCd, Skill_CheckCd_Hook);
        HookManager::install(app::Skill_CheckCost, Skill_CheckCost_Hook);
      //  HookManager::install(app::Skill_CheckState, Skill_CheckState_Hook);
        //HookManager::install(app::SC_SYNC_ULTIMATE_SP_CELL_CNT_get_UltimateSpCellCnt, SC_SYNC_ULTIMATE_SP_CELL_CNT_get_UltimateSpCellCnt_Hook);
        HookManager::install(app::AbilitySystem_get_ultimateSp, AbilitySystem_get_ultimateSp_Hook);

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
    //int32_t SC_SYNC_ULTIMATE_SP_CELL_CNT_get_UltimateSpCellCnt_Hook(void/*SC_SYNC_ULTIMATE_SP_CELL_CNT*/* __this, app::MethodInfo* method) {
    //    auto& CoolDown = CoolDown::getInstance();
    //    if (CoolDown.f_Enabled) {
    //        return (int32_t)100;
    //    }
    //    else
    //       return  CALL_ORIGIN(SC_SYNC_ULTIMATE_SP_CELL_CNT_get_UltimateSpCellCnt_Hook, __this, method);
    //
    //
    //}

    float AbilitySystem_get_ultimateSp_Hook(void/*AbilitySystem*/* __this, app::MethodInfo* method) {
        auto& CoolDown = CoolDown::getInstance();
        if (CoolDown.f_Enabled.getValue()) {
            return (float)1000;
        }
        else
           return  CALL_ORIGIN(AbilitySystem_get_ultimateSp_Hook, __this, method);
    
    }
}
