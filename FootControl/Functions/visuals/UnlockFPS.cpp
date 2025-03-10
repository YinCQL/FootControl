﻿#include "UnlockFPS.h"

namespace cheat {
	static void Global_UpdateFps_Hook(void* __this);

	UnlockFPS::UnlockFPS() {
		f_Enabled = config::getValue("functions:UnlockFPS", "enabled", false);
		f_EnabledLimit = config::getValue("functions:UnlockFPS:Limit", "enabled", false);
		f_Fps = config::getValue("functions:UnlockFPS", "value", 60);
		f_FpsLimit = config::getValue("functions:UnlockFPS:Limit", "value", 60);
		f_Hotkey = Hotkey("functions:UnlockFPS");

		HookManager::install(app::GameApp_Update, Global_UpdateFps_Hook);
	}

	UnlockFPS& UnlockFPS::getInstance() {
		static UnlockFPS instance;
		return instance;
	}

	void UnlockFPS::GUI() {
		//ImGui::SeparatorText(_("UnlockFPS"));
		ConfigCheckbox(_("Unlock FPS"), f_Enabled, _("Unlocks higher framerate."));
		ImGui::SameLine();
		f_Hotkey.Draw();

		if (f_Enabled.getValue()) {
			ImGui::Indent();
			ConfigSliderInt(_("FPS"), f_Fps, 1, 360);
			ConfigCheckbox(_("Lock FPS"), f_EnabledLimit, _("Limit framerate while the game window isn't focused.\n"
				"This won't work if the cheat menu is open or if you're in a loading screen."));

			if (f_EnabledLimit.getValue())
				ConfigSliderInt(_("FPS Limit"), f_FpsLimit, 1, 360);

			ImGui::Unindent();
		}
	}

	void UnlockFPS::Outer() {
		if (f_Hotkey.IsPressed())
			f_Enabled.setValue(!f_Enabled.getValue());
	}

	void UnlockFPS::Status() {
		if (f_Enabled.getValue())
			ImGui::Text("Unlock FPS: %i", f_Fps.getValue());
	}

	std::string UnlockFPS::getModule() {
		return _("Visuals");
	}

	void Global_UpdateFps_Hook(void* __this) {
		auto& unlockFPS = UnlockFPS::getInstance();
		bool enabled = unlockFPS.f_Enabled.getValue();
		int fps = unlockFPS.f_Fps.getValue();

		app::Application_set_targetFrameRate(enabled ? fps : 60,nullptr);
		app::QualitySettings_set_vSyncCount(enabled ? 0 : 1, nullptr);

		if (enabled) {
			if (!unlockFPS.f_EnabledLimit.getValue())
				app::Application_set_targetFrameRate(fps, nullptr);
			else {
				if (!app::Application_get_isFocused( nullptr))
					app::Application_set_targetFrameRate(unlockFPS.f_FpsLimit.getValue(), nullptr);
				else
					app::Application_set_targetFrameRate(fps, nullptr);
			}
		}

		CALL_ORIGIN(Global_UpdateFps_Hook, __this);
	}
}
