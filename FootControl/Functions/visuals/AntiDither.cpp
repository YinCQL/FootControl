#include "AntiDither.h"

namespace cheat {
	//static bool EntityRenderAlphaDitherController_SetDitherAlpha_Hook(void/*EntityRenderAlphaDitherController*/* __this, float alpha, int32_t handle, app::MethodInfo* method);
	//static void EntityRenderAlphaDitherController__SetMaterialDitherAlpha_Hook(void/*EntityRenderAlphaDitherController*/* __this, float value, app::MethodInfo* method);
	static void EntityRenderHelper_SetDitherAlpha_Hook(void/*EntityRenderHelper*/* __this, float ditherAlpha, int32_t handle, app::MethodInfo* method);
	AntiDither::AntiDither() : Function() {
		f_Enabled = config::getValue("functions:AntiDither", "enabled", false);

		f_Hotkey = Hotkey("functions:AntiDither");

		//HookManager::install(app::EntityRenderAlphaDitherController_SetDitherAlpha, EntityRenderAlphaDitherController_SetDitherAlpha_Hook);
  //      HookManager::install(app::EntityRenderAlphaDitherController__SetMaterialDitherAlpha, EntityRenderAlphaDitherController__SetMaterialDitherAlpha_Hook);
        HookManager::install(app::EntityRenderHelper_SetDitherAlpha, EntityRenderHelper_SetDitherAlpha_Hook);
	}

	AntiDither& AntiDither::getInstance() {
		static AntiDither instance;
		return instance;
	}

	void AntiDither::GUI() {
		ConfigCheckbox(_("AntiDither"), f_Enabled, _("AntiDither"));

		if (f_Enabled.getValue()) {
			ImGui::Indent();
			f_Hotkey.Draw();
			ImGui::Unindent();
		}
	}

	void AntiDither::Outer() {
		if (f_Hotkey.IsPressed())
			f_Enabled.setValue(!f_Enabled.getValue());
	}

	void AntiDither::Status() {
		if (f_Enabled.getValue())
			ImGui::Text(_("AntiDither"));
	}

	std::string AntiDither::getModule() {
		return _("Visuals");
	}


	//bool EntityRenderAlphaDitherController_SetDitherAlpha_Hook(void/*EntityRenderAlphaDitherController*/* __this, float alpha, int32_t handle, app::MethodInfo* method) {
	//	auto& AntiDither = cheat::AntiDither::getInstance();
	//	bool enabled = AntiDither.f_Enabled.getValue();
	//	LOG_DEBUG("AntiDither0: %f", alpha);
	//	if (enabled)
	//		return CALL_ORIGIN(EntityRenderAlphaDitherController_SetDitherAlpha_Hook, __this, 1.0f, handle, method);

	//	return CALL_ORIGIN(EntityRenderAlphaDitherController_SetDitherAlpha_Hook, __this, alpha, handle, method);
	//}
	//void EntityRenderAlphaDitherController__SetMaterialDitherAlpha_Hook(void/*EntityRenderAlphaDitherController*/* __this, float value, app::MethodInfo* method) {
	//	auto& AntiDither = cheat::AntiDither::getInstance();
	//	bool enabled = AntiDither.f_Enabled.getValue();
	//	LOG_DEBUG("AntiDither1: %f", value);
	//	if (enabled)
	//		return CALL_ORIGIN(EntityRenderAlphaDitherController__SetMaterialDitherAlpha_Hook, __this, 1.0f,  method);

	//	return CALL_ORIGIN(EntityRenderAlphaDitherController__SetMaterialDitherAlpha_Hook, __this, value,  method);
	//}

    void EntityRenderHelper_SetDitherAlpha_Hook(void/*EntityRenderHelper*/* __this, float ditherAlpha, int32_t handle, app::MethodInfo* method) {
		auto& AntiDither = cheat::AntiDither::getInstance();
		bool enabled = AntiDither.f_Enabled.getValue();
		//LOG_DEBUG("AntiDither2: %f", ditherAlpha);
		if (enabled)
			return CALL_ORIGIN(EntityRenderHelper_SetDitherAlpha_Hook, __this, 1.0f, handle, method);

		return CALL_ORIGIN(EntityRenderHelper_SetDitherAlpha_Hook, __this, ditherAlpha, handle, method);
    }
}
