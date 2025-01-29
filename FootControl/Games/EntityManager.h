#pragma once
#include "Entity.h"
#include <vector>


namespace cheat {

	cheat::Entity GetPlayerEntity();

	std::vector<cheat::Entity> GetAllEntity();

	std::string TRRawName(const std::string& idPrefix);
}





