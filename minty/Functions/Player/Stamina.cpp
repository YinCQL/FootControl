#include "Stamina.h"

namespace cheat {
    static uint32_t  SC_SYNC_STAMINA_get_CurStamina_Hook(app::SC_SYNC_STAMINA* __this, app::MethodInfo* method);

    Stamina::Stamina() {
        f_Enabled = config::getValue("functions:Stamina", "enabled", false);

        f_Hotkey = Hotkey("functions:Stamina");

        HookManager::install(app::SC_SYNC_STAMINA_get_CurStamina, SC_SYNC_STAMINA_get_CurStamina_Hook);
    


    }

    Stamina& Stamina::getInstance() {
        static Stamina instance;
        return instance;
    }

    void Stamina::GUI() {
        if (ConfigCheckbox(_("Stamina"), f_Enabled, _("Stamina_DESCRIPTION"))) {
            //ImGui::Indent();
            //f_Hotkey.Draw();
            //ImGui::Unindent();
        }
    }

    void Stamina::Outer() {
        //if (f_Hotkey.IsPressed())
        //{
        //    f_Enabled.setValue(!f_Enabled.getValue());
        //}
    }

    void Stamina::Status() {
        if (f_Enabled)
            ImGui::Text(_("Stamina"));
    }

    std::string Stamina::getModule() {
        return _("Player");
    }



    uint32_t  SC_SYNC_STAMINA_get_CurStamina_Hook(app::SC_SYNC_STAMINA* __this, app::MethodInfo* method) {
        auto& Stamina = Stamina::getInstance();
        if (Stamina.f_Enabled) {
            __this->fields.curStamina_ = __this->fields.maxStamina_;
        }
        
        return CALL_ORIGIN(SC_SYNC_STAMINA_get_CurStamina_Hook, __this, method);
    
    }

}
