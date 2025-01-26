#include "ConfigManager.h"

namespace config {
    void save(json config) {
        std::ofstream configFile("FootJob.json");

        configFile << config.dump(4) << "\n";
        configFile.close();
    }
}
