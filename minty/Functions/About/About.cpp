#include "About.h"

namespace cheat {
	About::About() {

	}
	void About::GUI() {
		ImGui::SeparatorText(_("About"));
		ImGui::Text(_("This software is free, if you spend money to get it, then you will be deceived"));
		ImGui::Text(_("footjob version : %s"), "0.9.0");
		ImGui::Text(_("Game server support :  cbt2os "));
		//ImGui::Text("ImGui version: %s", ImGui::GetVersion());
		ImGui::Text("Founder : ");
		TextURL("Gktwo", "https://github.com/Gktwo", true, false);

		//ImGui::TextColored(ImVec4(235.0F / 255.0F, 64.0F / 255.0F, 52.0F / 255.0F, 1.0),
		//	"%s: MintyGingy", _("ABOUT_OWNER"));
		//ImGui::TextColored(ImVec4(219.0F / 255.0F, 57.0F / 255.0F, 219.0F / 255.0F, 1.0),
		//	"%s: Moistcrafter", _("ABOUT_CO-FOUNDER"));
		//ImGui::TextColored(ImVec4(57.0F / 255.0F, 68.0F / 255.0F, 219.0F / 255.0F, 1.0),
		//	"%s: EtoShinya, KittyKate, lilmayofuksu, USSY, akioukun, sad_akulka, Micah, wat3r1ng", _("ABOUT_CONTRIBUTORS"));
		//ImGui::TextColored(ImVec4(255, 0, 212, 255),
		//	"%s: Thomas_Heath, Blair, unmeinoshonen, USSY", _("ABOUT_DONATERS"));
		//ImGui::TextColored(ImVec4(0, 255, 179, 255),
		//	"%s: Futchev, yarik0chka, keitaro_gg", _("ABOUT_FAMILY"));
		//ImGui::TextColored(ImVec4(212, 0, 179, 255),
		//	"%s: Micah, Amireux, d3adp3r50n, Niko", _("ABOUT_TRANSLATORS"));





	}

	std::string About::getModule() {
		return _("About");
	}

	About& About::getInstance() {
		static About instance;
		return instance;
	}
}
