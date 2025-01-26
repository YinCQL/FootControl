#include "AntiDither.h"
//bool, EntityRenderAlphaDitherController_SetDitherAlpha, (void*/*EntityRenderAlphaDitherController*/* __this, float alpha, int32_t handle, MethodInfo* method));
namespace cheat {
	static bool EntityRenderAlphaDitherController_SetDitherAlpha(void*/*EntityRenderAlphaDitherController*/* __this, float alpha, int32_t handle, app::MethodInfo* method);

	AntiDither::AntiDither() : Function() {
		f_Enabled = config::getValue("functions:AntiDither", "enabled", false);

		f_Hotkey = Hotkey("functions:AntiDither");

		HookManager::install(app::EntityRenderAlphaDitherController_SetDitherAlpha, EntityRenderAlphaDitherController_SetDitherAlpha);
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

	static bool _prevEnabledState = false;

	//void onUpdate_AntiDither(app::UnityEngine_EventSystems_EventSystem_o* __this, app::MethodInfo* method) {
	//	auto& AntiDither = AntiDither::getInstance();
	//	bool enabled = AntiDither.f_Enabled.getValue();

	//	if (_prevEnabledState != enabled) {
	//		app::RenderSettings_set_fog(!enabled);
	//		_prevEnabledState = enabled;
	//	}
	//	CALL_ORIGIN(onUpdate_AntiDither, __this, method);
	//}

	bool EntityRenderAlphaDitherController_SetDitherAlpha(void*/*EntityRenderAlphaDitherController*/* __this, float alpha, int32_t handle, app::MethodInfo* method) {
		auto& AntiDither = cheat::AntiDither::getInstance();
		bool enabled = AntiDither.f_Enabled.getValue();

		if (enabled)
			return CALL_ORIGIN(EntityRenderAlphaDitherController_SetDitherAlpha, __this, 1.0f, handle, method);

		return CALL_ORIGIN(EntityRenderAlphaDitherController_SetDitherAlpha, __this, alpha, handle, method);
	}
}
