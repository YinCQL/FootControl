import os

def generate_font_header(font_file, header_file):
    try:
        with open(font_file, "rb") as f:
            font_data = f.read()
    except FileNotFoundError:
        print(f"Error: Font file '{font_file}' not found.")
        return

    array_name = os.path.splitext(os.path.basename(font_file))[0].replace("-", "_").replace(".", "_") #Creates a valid variable name
    with open(header_file, "w") as h:
        h.write("#pragma once\n")
        h.write("#include <cstddef>\n\n")
        h.write("namespace FontData {\n")
        h.write(f"    extern const unsigned char {array_name}[] = {{\n")
        for i, byte in enumerate(font_data):
            h.write(f"        0x{byte:02x},")
            if (i + 1) % 16 == 0:
                h.write("\n")
            else:
                h.write(" ")
        h.write("\n    };\n")
        h.write(f"    inline constexpr size_t {array_name}_size = sizeof({array_name});\n")
        h.write("}\n")
    print(f"{header_file} generated successfully.")

if __name__ == "__main__":
    font_file = "H7GBKHeavy.TTF"  # Replace with your font file
    header_file = "font_data.h"
    generate_font_header(font_file, header_file)