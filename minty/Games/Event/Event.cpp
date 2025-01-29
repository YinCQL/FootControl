#include "Event.h"

namespace cheat
{
	bool IsInWorld = false;

	bool IsInGame() {
		try
		{
			auto state = app::GameApp_get_currentState(app::GameApp_get_instance(), nullptr);
			if (state == app::GameState__Enum::GameState__Enum_Main)
				return true;
			return false;
		}
		catch (const std::exception&)
		{
			return false;
		}

	}
	void NetTpto(app::Vector3 pos, int32_t levelId) {
		app::GameplayNetwork_C2STeleport(app::GameInstance_get_gameplayNetwork(), levelId, app::TeleportReason__Enum::TeleportReason__Enum_Action,pos, app::Vector3(0.f, 0.f, 0.f), nullptr);
	
	
	}
	void Tpto(app::Vector3 pos) {
		
		//auto world =app::GameInstance_get_world();
		//app::FunctionAreaManager * area = app::GameWorld_get_functionAreaManager(world, nullptr);
		//app::String* levelId = string_to_il2cppi(std::to_string(area->fields.m_currentLevelId));
		//LOG_DEBUG("levelId %d",il2cppi_to_string(levelId).c_str());
		//app::GameAction_TeleportTo(levelId,app::TeleportReason__Enum::TeleportReason__Enum_Map,pos,app::Vector3(0,0,0),nullptr);
		app::GameAction_TeleportTeam(pos, app::Vector3(0.f, 0.f, 0.f), nullptr);
	}

	int32_t GetLevelId() {
		return  app::GameUtil_LevelIdStringToNum(app::GameUtil_GetCntLevelId());
	
	}


}