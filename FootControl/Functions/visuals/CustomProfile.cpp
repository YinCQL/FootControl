#include "CustomProfile.h"

namespace cheat {
	//app::String*, UtilsForLua_GetCurrentUID, ());
	//static app::String* UtilsForLua_GetCurrentUID_Hook();
	static  app::String* TMP_Text_get_text_Hook(void/*TMP_Text*/* __this, app::MethodInfo* method);
	void* UIDTMP_Text_1 = nullptr;
	void* UIDTMP_Text_2 = nullptr;
	app::String* orginuid=nullptr;
	CustomProfile::CustomProfile() : Function() {
		f_Enabled = config::getValue("functions:CustomProfile", "enabled", false);
		f_UIDtext = config::getValue<std::string>("functions:CustomProfile", "UIDtext", "");

		f_Hotkey = Hotkey("functions:CustomProfile");

		HookManager::install(app::TMP_Text_get_text, TMP_Text_get_text_Hook);
		//HookManager::install(app::UtilsForLua_GetCurrentUID, UtilsForLua_GetCurrentUID_Hook);
	}

	CustomProfile& CustomProfile::getInstance() {
		static CustomProfile instance;
		return instance;
	}

	void CustomProfile::GUI() {
		bool set = f_Enabled.getValue();
		ConfigCheckbox(_("CustomProfile"), f_Enabled, _("CustomProfile"));
		if (set != f_Enabled.getValue())
		{
			if (f_Enabled.getValue()) {
				if (UIDTMP_Text_1 != nullptr)
					app::TMP_Text_set_text(UIDTMP_Text_1, string_to_il2cppi(f_UIDtext.getValue()), nullptr);
				if (UIDTMP_Text_2 != nullptr)
					app::TMP_Text_set_text(UIDTMP_Text_2, string_to_il2cppi(f_UIDtext.getValue()), nullptr);
			}
			else
			{
				if (UIDTMP_Text_1 != nullptr)
					app::TMP_Text_set_text(UIDTMP_Text_1, orginuid, nullptr);
				if (UIDTMP_Text_2 != nullptr)
					app::TMP_Text_set_text(UIDTMP_Text_2, orginuid, nullptr);
			}

		}
		if (f_Enabled.getValue()) {
			ImGui::Indent();
			ConfigInputText(_("UID"), f_UIDtext, "");
			ImGui::Unindent();
		}
	}

	void CustomProfile::Outer() {
		if (f_Hotkey.IsPressed())
			f_Enabled.setValue(!f_Enabled.getValue());
	}

	void CustomProfile::Status() {
		if (f_Enabled.getValue())
			ImGui::Text(_("CustomProfile"));
	}

	std::string CustomProfile::getModule() {
		return _("Visuals");
	}



	//app::String* UtilsForLua_GetCurrentUID_Hook() {

	//	auto& CustomProfile = cheat::CustomProfile::getInstance();
	//	if (CustomProfile.f_Enabled.getValue()) {
	//		return string_to_il2cppi(CustomProfile.f_UIDtext.getValue());
	//	}
	//	return CALL_ORIGIN(UtilsForLua_GetCurrentUID_Hook);
	//}

	app::String* TMP_Text_get_text_Hook(void/*TMP_Text*/* __this, app::MethodInfo* method) {


		auto a = CALL_ORIGIN(TMP_Text_get_text_Hook, __this, method);
		if (il2cppi_to_string(a).starts_with("UID:")) {
			orginuid = a;
			if (UIDTMP_Text_1 == nullptr)
				UIDTMP_Text_1 = __this;
			else if (UIDTMP_Text_2 == nullptr)
				UIDTMP_Text_2 = __this;
			if (cheat::CustomProfile::getInstance().f_Enabled.getValue()) {
				return string_to_il2cppi(cheat::CustomProfile::getInstance().f_UIDtext.getValue());
			}

		}

		return a;
	}
}