#include "Debug.h"
//#include "../../api/json/json.hpp"
//using json = nlohmann::json;
#include "../../Games/EntityManager.h"
namespace cheat {
	float tpx;
    float tpy;
    float tpz;
	int32_t mapid;
	static void EventSystem_RaycastAll_Hook (void/*EventSystem*/* __this, void  /*PointerEventData*/* eventData, app::List_1_UnityEngine_EventSystems_RaycastResult_* raycastResults, app::MethodInfo* method);
	//DO_APP_FUNC(0x0C71CA40, app::String*, TMP_Text_get_text, (void/*TMP_Text*/* __this, MethodInfo* method));
	//DO_APP_FUNC(0x0C71CB20, void, TMP_Text_set_text, (void/*TMP_Text*/* __this, app::String* value, MethodInfo* method));
	

	Debug::Debug() {
		//f_Enabled = config::getValue("functions:Debug", "enabled", false);

		f_Resolution = Hotkey("functions:Debug:SetResolution");
		f_Resolutionwidth = config::getValue("functions:Debug:Resolution", "widthvalue", 1600);
		f_Resolutionheight = config::getValue("functions:Debug:Resolution", "heightvalue", 900);
		f_Resolutionfullscreen = config::getValue("functions:Debug:Resolution", "fullscreenvalue", false);
		f_UIInspector = config::getValue("functions:Debug", "UIInspector", false);
		HookManager::install(app::EventSystem_RaycastAll, EventSystem_RaycastAll_Hook);// 获取鼠标下组件
		//HookManager::install(app::Debug_1_get_developerConsoleEnabled, Debug_1_get_developerConsoleEnabled_Hook);
  //      HookManager::install(app::Debug_1_set_developerConsoleEnabled, Debug_1_set_developerConsoleEnabled_Hook);
		

	}

	Debug& Debug::getInstance() {
		static Debug instance;
		return instance;
	}

	void Debug::GUI() {
		ImGui::SeparatorText(_("Debug"));

		if (ImGui::Button("SetResolution"))
			SetResolution();
		ImGui::SameLine();
		f_Resolution.Draw();
		ConfigInputInt(_("Screen width"), f_Resolutionwidth, _("RESOLUTION_WIDTH_DESCRIPTION"));
		ConfigInputInt(_("Screen height"), f_Resolutionheight, _("RESOLUTION_HEIGHT_DESCRIPTION"));
		ConfigCheckbox(_("Fullscreen"), f_Resolutionfullscreen, _("Fullscreen"));

		//if (ImGui::Button("find cam"))
		//{
		//	auto maincam = app::Camera_get_main(nullptr);
		//	//auto currcam = app::Camera_get_current(nullptr);
		//	LOG_DEBUG("mainCam Component %p", maincam);
		//	auto maincamgobj = app::Component_get_gameObject(reinterpret_cast<app::Component*>(maincam), nullptr);
		//	auto name = app::Object_1_get_name(reinterpret_cast<app::Object_1*>(maincamgobj), nullptr);//Main Camera
		//	LOG_DEBUG("mainCam Gameobject:%s ,%p", il2cppi_to_string(name), maincamgobj);
		//	app::String* findname = string_to_il2cppi("Main Camera");
		//	auto findcam = app::GameObject_Find(findname, nullptr);
		//	LOG_DEBUG("mainCam namefindtest:%p", findcam);
		//	auto maincamtr = app::GameObject_get_transform(maincamgobj, nullptr);
		//	LOG_DEBUG("mainCam tranform:%p", maincamtr);
		//	auto CinemachineBrain = app::GameObject_GetComponentByName(maincamgobj, string_to_il2cppi("CinemachineBrain"), nullptr);
		//	auto CinemachineExternalCamera = app::GameObject_GetComponentByName(maincamgobj, string_to_il2cppi("CinemachineExternalCamera"), nullptr);
		//	LOG_DEBUG("mainCam CB:%p,CEC:%p", CinemachineBrain, CinemachineExternalCamera);
		//}

		//if (ImGui::Button("entity"))
		//{
		//	//auto list = app::GameWorld_get_allEntities(app::GameInstance_get_world(nullptr), nullptr);
		//	////list->fields.m_items
		//	//LOG_DEBUG("Entity list count %d", (int)(list->fields._count_k__BackingField));
		//	//for (int i = 0; i < list->fields._count_k__BackingField; i++)
  // //         {
		//	//	auto entity = list->fields.m_items->vector[i].obj;
  // //             auto name = il2cppi_to_string(app::Entity_get_name(entity, nullptr));
  // //             LOG_DEBUG("Entity %d:%s", i, name.c_str());
  // //         }
		//	auto list = GetAllEntity();
		//	LOG_DEBUG("Entity %d",  list.size());
  //          for (int i = 0; i < list.size(); i++)
  //          {
		//	cheat::Entity entity = list[i];
  //              auto name = entity.getName();
  //              LOG_DEBUG("Entity %d:%s", i, name.c_str());
  //          }
		//}

		ImGui::Separator();
		if (cheat::IsInWorld) {
			auto pos = app::GameUtil_get_playerPos();
			ImGui::Text("PlayerPos (%f,%f,%f)", pos.x, pos.y, pos.z);
		}
		//auto text = il2cppi_to_string(app::I18nUtils_GetText(string_to_il2cppi("CD52E42DDB72692B")));
		//ImGui::Text("i18ntest CD52E42DDB72692B: %s",text.c_str() );
		ImGui::Separator();
		if (ImGui::Button("tp")) {
			Tpto(app::Vector3(tpx, tpy, tpz));
		}
		ImGui::SameLine();
		if (ImGui::Button("tp by map")) {
			NetTpto(app::Vector3(tpx, tpy, tpz), mapid);
		}
		ImGui::InputFloat("x", &tpx);
		ImGui::InputFloat("y", &tpy);
		ImGui::InputFloat("z", &tpz);
		ImGui::InputInt("MapId", &mapid);
		ConfigCheckbox(_("Mouse UI in Inspector"), f_UIInspector, _("Mouse UI in Inspector"));
		if (ImGui::Button("find level objs")) {
			

		}
	}


	void Debug::Outer() {
		//if (f_Hotkey.IsPressed())
		//	f_Enabled.setValue(!f_Enabled.getValue());
		if (f_Resolution.IsPressed())
			SetResolution();


	}



	void Debug::Status() {
		//if (f_Enabled.getValue())
		//	ImGui::Text(_("Debug"));
	}

	std::string Debug::getModule() {
		return "Debug";
	}



	void Debug::SetResolution() {
		if (f_Resolutionwidth.getValue() != 0 && f_Resolutionheight.getValue() != 0)
		{
			app::Screen_SetResolution(f_Resolutionwidth.getValue(), f_Resolutionheight.getValue(), f_Resolutionfullscreen.getValue(), nullptr);

		}

		LOG_INFO("SetResolution to %d x %d, fullscreen: %s", f_Resolutionwidth.getValue(), f_Resolutionheight.getValue(), f_Resolutionfullscreen.getValue() ? "true" : "false");

	}
	void EventSystem_RaycastAll_Hook(void/*EventSystem*/* __this, void  /*PointerEventData*/* eventData, app::List_1_UnityEngine_EventSystems_RaycastResult_* raycastResults, app::MethodInfo* method) {

		CALL_ORIGIN(EventSystem_RaycastAll_Hook, __this, eventData, raycastResults, method);
		auto& Debug =Debug::getInstance();
		if (Debug.f_UIInspector.getValue()) {
			auto  items = raycastResults->fields._items;
			auto count = raycastResults->fields._size;

			for (int i = 0; i < count; i++) {
				auto& raycastResult = items->vector[i];
				auto a = reinterpret_cast<app::Object_1*>(raycastResult.m_GameObject);
				LOG_DEBUG("OBJ: %s childcount:%d", il2cppi_to_string(app::Object_1_get_name(a, nullptr)).c_str(), app::Transform_GetChildCount(app::GameObject_get_transform(raycastResult.m_GameObject, nullptr), nullptr));
			}
		}

	}

	//void PrintGameObjectPath(app::Transform* transform, const std::string& path = "") {
	//	if (!transform) return;

	//	// 获取当前对象的名称
	//	app::GameObject* gameObject = app::Component_get_gameObject(reinterpret_cast<app::Component*>(transform),nullptr);
	//	if (!gameObject) return;

	//	std::string currentPath = path.empty() ? il2cppi_to_string(app::Object_1_get_name(reinterpret_cast<app::Object_1*>(gameObject),nullptr)): path + "/" + il2cppi_to_string(app::Object_1_get_name(reinterpret_cast<app::Object_1*>(gameObject), nullptr));

	//	// 输出完整路径
	//	std::cout << "obj: "<<currentPath << std::endl;

	//	// 遍历所有子物体
	//	int childCount = app::Transform_get_childCount(transform,nullptr);
	//	for (int i = 0; i < childCount; i++) {
	//		app::Transform* child = app::Transform_GetChild(transform, i,nullptr);
	//		PrintGameObjectPath(child, currentPath);
	//	}
	//}

	//void DumpRootGameObjects() {
	//	// 获取当前场景所有的 Transform 组件
	//	auto* allTransforms = app::Object_1_FindObjectsOfType(<app::Transform>,nullptr);
	//	if (!allTransforms) return;

	//	int count = allTransforms->max_length;
	//	for (int i = 0; i < count; i++) {
	//		UnityEngine::Transform* transform = allTransforms->vector[i];
	//		if (!transform) continue;

	//		// 仅处理根对象（没有父级 Transform）
	//		if (UnityEngine::Transform::get_parent(transform) == nullptr) {
	//			PrintGameObjectPath(transform);
	//		}
	//	}
	//}


}