#include "ConfigManager.h"

namespace config {
    void save(json config) {
        std::ofstream configFile("FootControl.json");

        configFile << config.dump(4) << "\n";
        configFile.close();
    }
}
