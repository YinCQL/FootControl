#include "../functions/about/About.h"
#include "../functions/settings/Settings.h"

#include "../functions/player/Damage.h"

#include "../functions/player/CoolDown.h"
#include "../functions/player/Stamina.h"
#include "../functions/player/PlayerSpeed.h"

#include "../functions/world/DumbMonster.h"
#include "../functions/world/SkipPlot.h"
#include "../functions/world/SetTimeScale.h"


#include "../functions/visuals/AntiDither.h"
#include "../functions/visuals/ESP.h"
#include "../functions/visuals/CustomProfile.h"
//#include "../functions/visuals/HideUI.h"
//#include "../functions/visuals/browser.h"

#include "../functions/visuals/UnlockFPS.h"
#include "../functions/visuals/freecamera.h"

#include "../functions/debug/Debug.h"


std::vector<std::string> ModuleOrder = {
	_("About"),
	_("Player"),
	_("World"),

	_("Visuals"),
			_("ESP"),
	_("Settings"),
	"Debug"

};

void Init() {
	//about
	INIT_FUNC(About);
	//player
	INIT_FUNC(Damage);
	INIT_FUNC(CoolDown);
	INIT_FUNC(Stamina);
    INIT_FUNC(PlayerSpeed);
	
	//world
	INIT_FUNC(SetTimeScale);
    INIT_FUNC(DumbMonster);
    INIT_FUNC(SkipPlot);





	//Visuals
	//INIT_FUNC(HideUI);
	INIT_FUNC(UnlockFPS);
    INIT_FUNC(AntiDither);
	//INIT_FUNC(Browser);
	//INIT_FUNC(NoFog);
	INIT_FUNC(FreeCamera);
    INIT_FUNC(CustomProfile);
	INIT_FUNC(ESP);
		//settings
	INIT_FUNC(Settings);
	//debug
	INIT_FUNC(Debug);

}

void Outer() {
	for (auto& func : functions)
		func->Outer();
}

void Status() {
	auto& settings = cheat::Settings::getInstance();

	if (!settings.f_Status.getValue())
		return;

	ImGuiWindowFlags flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
		ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoFocusOnAppearing;

	if (!settings.f_StatusMove.getValue())
		flags |= ImGuiWindowFlags_NoMove;
	ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[fontindex_menu]);
	ImGui::Begin(_("Status"), nullptr, flags);

	auto windowWidth = ImGui::GetWindowSize().x;
	auto& about = cheat::About::getInstance();
	std::string version = about.mVersion;

	ImGui::PushStyleColor(ImGuiCol_Text, { 0.17f, 0.63f, 0.45f, 1.00f });
	ImGui::Text("FootControl");
	ImGui::PopStyleColor();
	ImGui::Separator();
	for (auto& feature : functions)
		feature->Status();
	ImGui::PopFont();
	ImGui::End();
}

void DrawSection(const std::string& moduleName) {
	for (auto& func : functions) {
		if (func->getModule() != moduleName)
			continue;

		func->GUI();
	}
}
