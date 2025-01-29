#include "PlayerSpeed.h"

namespace cheat {
    static void GameApp_Update_Hook(void/*Skill*/* __this);

    PlayerSpeed::PlayerSpeed() {
        f_Enabled = config::getValue("functions:PlayerSpeed", "enabled", false);
        f_Speed = config::getValue("functions:PlayerSpeed", "speed", 1.0f);
        f_Hotkey = Hotkey("functions:PlayerSpeed");

        HookManager::install(app::GameApp_Update, GameApp_Update_Hook);


    }

    PlayerSpeed& PlayerSpeed::getInstance() {
        static PlayerSpeed instance;
        return instance;
    }

    void PlayerSpeed::GUI() {
        if (ConfigCheckbox(_("PlayerSpeed"), f_Enabled, _("PlayerSpeed"))) {
            ImGui::Indent();
            ConfigDragFloat(_("Speed"), f_Speed, 1.0f, 1.0f, 10.0f, "");
            //f_Hotkey.Draw();
            ImGui::Unindent();
        }
    }

    void PlayerSpeed::Outer() {
        if (f_Hotkey.IsPressed())
        {
            f_Enabled.setValue(!f_Enabled.getValue());
        }
    }

    void PlayerSpeed::Status() {
        if (f_Enabled)
            ImGui::Text(_("PlayerSpeed"));
    }

    std::string PlayerSpeed::getModule() {
        return _("Player");
    }



    void GameApp_Update_Hook(void/*Skill*/* __this) {
        auto& PlayerSpeed = PlayerSpeed::getInstance();

        //if (PlayerSpeed.f_Enabled.getValue()) {
        //  //  PlayerSpeed.f_Speed.getValue()
        //    app::Entity* mainc = app::GameUtil_get_mainCharacter();



        //}
        return CALL_ORIGIN(GameApp_Update_Hook, __this);

    }
}
