#pragma once

#include <Windows.h>
#include <optional>
#include <libloaderapi.h>

#include "../../api/imgui/ImGui/imgui.h"

bool LoadFontFromMemory(ImFontConfig font_cfg, float size_pixels);
