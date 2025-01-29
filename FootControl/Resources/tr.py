import json

def generate_header(json_file, header_file):
    with open(json_file, 'r', encoding='utf-8') as f:
        data = f.read()

    with open(header_file, 'w', encoding='utf-8') as h:
        h.write("#pragma once\n")
        h.write("#include <string_view>\n\n")
        h.write("namespace LanguageData {\n")
        h.write(f"    inline constexpr std::string_view languageJson = R\"({data})\";\n") #Raw string literal
        h.write("}\n")

if __name__ == "__main__":
    generate_header("translations.json", "language_data.h")
    print("language_data.h generated")