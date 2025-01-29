#include "DumbMonster.h"

namespace cheat {
  //  void, EnemyAIBrain_SwitchAIMode, (void/*EnemyAIBrain*/* __this, app::EnemyAIModeType__Enum modeType, bool force, MethodInfo* method));
    static void  EnemyAIBrain_SwitchAIMode_Hook(void/*EnemyAIBrain*/* __this, app::EnemyAIModeType__Enum modeType, bool force, app::MethodInfo* method);

    DumbMonster::DumbMonster() {
        f_Enabled = config::getValue("functions:DumbMonster", "enabled", false);

        f_Hotkey = Hotkey("functions:DumbMonster");

        HookManager::install(app::EnemyAIBrain_SwitchAIMode, EnemyAIBrain_SwitchAIMode_Hook);
    


    }

    DumbMonster& DumbMonster::getInstance() {
        static DumbMonster instance;
        return instance;
    }

    void DumbMonster::GUI() {
        if (ConfigCheckbox(_("DumbMonster"), f_Enabled, _("DumbMonster"))) {
            //ImGui::Indent();
            //f_Hotkey.Draw();
            //ImGui::Unindent();
        }
    }

    void DumbMonster::Outer() {
        //if (f_Hotkey.IsPressed())
        //{
        //    f_Enabled.setValue(!f_Enabled.getValue());
        //}
    }

    void DumbMonster::Status() {
        if (f_Enabled)
            ImGui::Text(_("DumbMonster"));
    }

    std::string DumbMonster::getModule() {
        return _("World");
    }



    void EnemyAIBrain_SwitchAIMode_Hook(void/*EnemyAIBrain*/* __this, app::EnemyAIModeType__Enum modeType, bool force, app::MethodInfo* method) {
        if (DumbMonster::getInstance().f_Enabled) {
            if (modeType == app::EnemyAIModeType__Enum::EnemyAIModeType__Enum_Battle) {
                return;
               // modeType = app::EnemyAIModeType__Enum::EnemyAIModeType__Enum_Patrol;
            }
        }
       return CALL_ORIGIN( EnemyAIBrain_SwitchAIMode_Hook, __this, modeType, force, method);
    }

}
