#include "FontsLoader.h"
#include "../../Resources/font_data.h" // Include the generated header
#include "../../Utils/Logger.h"


bool LoadFontFromMemory(ImFontConfig font_cfg, float size_pixels) {
    // Check if the font data exists in the header
    if (FontData::H7GBKHeavy == nullptr || FontData::H7GBKHeavy_size == 0) {
        LOG_ERROR("Font data not found in header.");
        return false;
    }

    font_cfg.FontDataOwnedByAtlas = false;
    ImGui::GetIO().Fonts->AddFontFromMemoryTTF((void*)FontData::H7GBKHeavy, FontData::H7GBKHeavy_size, size_pixels, &font_cfg, ImGui::GetIO().Fonts->GetGlyphRangesChineseFull());
    return true;
}