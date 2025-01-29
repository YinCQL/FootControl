#include "Translations.h"
#include "../Functions/Settings/Settings.h"
#include <optional>
#include <string_view>
#include "../Resources/language_data.h" // Include the generated header

// Assuming language_data.h contains something like this:
// namespace LanguageData {
//   extern const std::string_view languageJson;
// }

enum class Lang {
    EN,
    CN
};

std::optional<std::string_view> safeGet(const nlohmann::json& json, const std::string_view& key, const Lang& lang) {
    const std::string_view langStr = magic_enum::enum_name(lang);

    if (json.contains(langStr) && json[langStr].is_object() && json[langStr].contains(key)) {
        return json[langStr][key].get<std::string_view>();
    }
    return std::nullopt; // Return std::nullopt when not found
}

const char* _(const char* code) {
    static nlohmann::json trJson;
    static bool initialized = false;
    static std::string u8result_storage; // Static storage for the result
    static const char* u8result_ptr = nullptr;

    if (!initialized) {
        try {
            trJson = nlohmann::json::parse(LanguageData::languageJson);
            initialized = true;
        }
        catch (nlohmann::json::parse_error& e) {
            LOG_ERROR("TR:JSON parsing error: %s", e.what());
            return code;
        }
    }

    int languageValue = cheat::Settings::getInstance().f_Language.getValue();
    std::optional<std::string_view> translation = safeGet(trJson, code, static_cast<Lang>(languageValue));

    if (!translation.has_value()) {
        translation = safeGet(trJson, code, Lang::EN);
    }
    if (!translation.has_value()) {
        translation = code;
    }

    // Use string_view to avoid unnecessary copies where possible
    std::string_view translation_view = translation.value();

    // Convert to UTF-8 only if necessary (if the source is not UTF-8)
    if (!std::all_of(translation_view.begin(), translation_view.end(), [](char c) { return (c & 0x80) == 0 || (c & 0xC0) == 0xC0; }))
    {
        u8result_storage = std::string(translation_view); // Create a copy for UTF-8 conversion
        u8result_ptr = u8result_storage.c_str();

    }
    else {
        u8result_ptr = translation_view.data();
    }

    return u8result_ptr;
}