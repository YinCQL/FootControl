#include "Stamina.h"

namespace cheat {
	static  int32_t Tables_GlobalConst_get_dashCostEnergyValue_Hook(void/*Tables_GlobalConst*/* __this, app::MethodInfo* method);

	Stamina::Stamina() {
		f_Enabled = config::getValue("functions:Stamina", "enabled", false);

		f_Hotkey = Hotkey("functions:Stamina");

		HookManager::install(app::Tables_GlobalConst_get_dashCostEnergyValue, Tables_GlobalConst_get_dashCostEnergyValue_Hook);


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

	int32_t Tables_GlobalConst_get_dashCostEnergyValue_Hook(void/*Tables_GlobalConst*/* __this, app::MethodInfo* method) {
		auto& stamina = cheat::Stamina::getInstance();
		if (stamina.f_Enabled.getValue()) {
			return 0;
		}
		return CALL_ORIGIN(Tables_GlobalConst_get_dashCostEnergyValue_Hook, __this, method);

	}


}
