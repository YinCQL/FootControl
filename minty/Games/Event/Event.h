#pragma once
#include "../../Functions/FunctionIncludes.h"



namespace cheat {
	bool IsInGame();
	extern bool IsInWorld;
	int32_t GetLevelId();
	void NetTpto(app::Vector3 pos, int32_t levelId);
	void Tpto(app::Vector3 pos);

}


