﻿#include "InitGui.h"

float alpha = 0;
void MergeIconsWithLatestFont(float font_size, bool FontDataOwnedByAtlas) {
    static const ImWchar icons_ranges[] = {ICON_MIN_FA, ICON_MAX_FA, 0};
    ImFontConfig icons_config;

    //icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.FontDataOwnedByAtlas = FontDataOwnedByAtlas;

    ImGui::GetIO().Fonts->AddFontFromMemoryTTF((void*)fa_solid_900, sizeof(fa_solid_900), font_size, &icons_config, icons_ranges);
}


void gui::InitImGui(HWND window, ID3D11Device* pDevice, ID3D11DeviceContext* pContext) {
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui_ImplWin32_Init(window);
    ImGui_ImplDX11_Init(pDevice, pContext);

    ImGui::GetIO().ImeWindowHandle = window;

    //ImFontConfig font_cfg;
    //font_cfg.FontDataOwnedByAtlas = false;
    io.Fonts->AddFontDefault();
    ImFontConfig myFontconfig;
    // init notify
    //MergeIconsWithLatestFont(16.f, false);
   // LoadThemes();
   setTheme(1);
    setStyle(1);
    //LoadFonts();
    LoadFontFromMemory(myFontconfig, 16.f);
    Init();
}

void gui::Render() {
    ImGui_ImplWin32_NewFrame();
    ImGui_ImplDX11_NewFrame();
    ImGui::NewFrame();
    Outer();
    Status();

    auto& settings = cheat::Settings::getInstance();
    static double startTime = ImGui::GetTime();
    static bool prevShowMenu = settings.f_ShowMenu.getValue();
    const float animDuration = settings.f_AnimationDuration.getValue();

    if (settings.f_ShowMenu.getValue() != prevShowMenu) {
        startTime = ImGui::GetTime(); 
        prevShowMenu = settings.f_ShowMenu.getValue();
    }

    float alpha = settings.f_ShowMenu.getValue() ? min(1.0f, (ImGui::GetTime() - startTime) / animDuration) : max(0.0f, 1.0f - (ImGui::GetTime() - startTime) / animDuration);

    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, alpha);

    if (settings.f_ShowMenu.getValue() || alpha > 0.0f)
        gui::FrameLoadGui();

    ImGui::PopStyleVar();

    //ImGui::GetIO().MouseDrawCursor = settings.f_ShowMenu.getValue();
    
    ImGui::Render();
}
