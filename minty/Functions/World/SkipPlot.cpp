#include "SkipPlot.h"

namespace cheat {
  // DO_APP_FUNC(0x070C88E0, void, DialogManager__DoPlayDialog, (void/*DialogManager*/* __this, MethodInfo* method));
  //  DO_APP_FUNC(0x070CAA10, void, DialogManager__ExitDialog, (void/*DialogManager*/* __this, bool isSkip, MethodInfo* method));
    static void  DialogManager__DoPlayDialog_Hook(void/*DialogManager*/* __this, app::MethodInfo* method);

    SkipPlot::SkipPlot() {
        f_Enabled = config::getValue("functions:SkipPlot", "enabled", false);

        f_Hotkey = Hotkey("functions:SkipPlot");

        HookManager::install(app::DialogManager__DoPlayDialog, DialogManager__DoPlayDialog_Hook);
    


    }

    SkipPlot& SkipPlot::getInstance() {
        static SkipPlot instance;
        return instance;
    }

    void SkipPlot::GUI() {
        if (ConfigCheckbox(_("SkipPlot"), f_Enabled, _("SkipPlot"))) {
            //ImGui::Indent();
            //f_Hotkey.Draw();
            //ImGui::Unindent();
        }
    }

    void SkipPlot::Outer() {
        //if (f_Hotkey.IsPressed())
        //{
        //    f_Enabled.setValue(!f_Enabled.getValue());
        //}
    }

    void SkipPlot::Status() {
        if (f_Enabled)
            ImGui::Text(_("SkipPlot"));
    }

    std::string SkipPlot::getModule() {
        return _("World");
    }




    void DialogManager__DoPlayDialog_Hook(void/*DialogManager*/* __this, app::MethodInfo* method) {

        CALL_ORIGIN(DialogManager__DoPlayDialog_Hook, __this, method);
        if (SkipPlot::getInstance().f_Enabled) {
            app::DialogManager__ExitDialog(__this, true, nullptr);
        }
        return;
    }


}
