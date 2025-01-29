#include "il2cpp-types.h"
//#include "il2cpp-enum.h"


using namespace app;


//globalupdate
//UnityEngine.EventSystems.EventSystem$$Update
//DO_APP_FUNC(0x024E4CF0,  void, EventSystem_Update, ( app::EventSystem* __this, app::MethodInfo* method));
DO_APP_FUNC(0x03373CB0, void, GameApp_Update, (void* __this));
DO_APP_FUNC(0x033736D0, void/*GameApp*/*, GameApp_get_instance, ());
DO_APP_FUNC(0x033737A0, app::GameState__Enum, GameApp_get_currentState, (void/*GameApp*/* __this, app::MethodInfo* method));
DO_APP_FUNC(0x0337A7F0, void, GameStartState__OnEnterMainGame, (void/*GameStartState*/* __this, MethodInfo* method));

DO_APP_FUNC(0x0CB7D7B0, void, EventSystem_RaycastAll, (void/*EventSystem*/* __this, void  /*PointerEventData*/* eventData, app::List_1_UnityEngine_EventSystems_RaycastResult_* raycastResults, app::MethodInfo* method));

//damage

DO_APP_FUNC(0x07C5BF20, void/*app::BattleNormalEffect*/*, EffectManager_CreateEffectOnTarget, (void/*EffectManager*/* __this, void/*EffectActionCfg*/* effectCfg, void/*app::AbilitySystem*/* target, app::Vector3 dir, void/*ITickOwner*/* timeScaleSource, app::String* overrideName,void /*app::AbilitySystem*/* source));

//DO_APP_FUNC(0x07061FB0, bool, BattleHitReactionManager_TryGetHitInfo, (BattleHitReactionManager* __this, ECSColliderResultProxy collider, Vector3 hitPoint, BattleHitReactionManager_HitInfo* hitInfo, app::MethodInfo* method));

//DO_APP_FUNC(0x083DA6C0, AbilitySystem_Modifier, AbilitySystem_Modifier_NewDamage, (AbilitySystem* source, AbilitySystem* target, double value, DamageType__Enum damageType, DamageDecorateMask__Enum damageDecorateMask, AbilitySystem_Modifier_DamageVisualImportance__Enum damageVisualImportance, bool isCritical, String* damageSourceId, AbilitySystem_Modifier_DamageVisualCoalition* damageVisualCoalition, Nullable_1_UnityEngine_Vector3_ hitPoint, bool hideMainCharHpScreenEffect, app::MethodInfo* method));
//DO_APP_FUNC(0x083DAA30, AbilitySystem_Modifier, AbilitySystem_Modifier_NewDamage_1, (AbilitySystem* source, AbilitySystem* target, double value, DamageType__Enum damageType, DamageDecorateMask__Enum damageDecorateMask, AbilitySystem_Modifier_DamageVisualImportance__Enum damageVisualImportance, bool isCritical, app::MethodInfo* method));
//DO_APP_FUNC(0x083DAC20, AbilitySystem_Modifier, AbilitySystem_Modifier_NewHeal, (AbilitySystem* source, AbilitySystem* target, double value, bool showText, app::MethodInfo* method));
//DO_APP_FUNC(0x083DAD30, AbilitySystem_Modifier, AbilitySystem_Modifier_NewHeal_1, (AbilitySystem* source, AbilitySystem* target, double value, bool showText, bool createBuff, app::MethodInfo* method));
//DO_APP_FUNC(0x07062390, void, BattleHitReactionManager_Hit, (void/*BattleHitReactionManager*/* __this, app::Entity* attacker, app::String* hitMethodId, float hitValue, bool dontHitImportantInteractive, app::BattleHitReactionManager_HitInfo hitInfo, app::MethodInfo* method));

//entity
DO_APP_FUNC(0x07A01760, GameWorld*, GameInstance_get_world, ());
//DO_APP_FUNC(0x07404B50, void, SceneGridContext_GetEntityList, (void/*SceneGridContext*/* __this, Vector3 pos, float radius, EEntityType__Enum entityType, List_1_Beyond_ObjectPtr_1__4* target, app::MethodInfo* method));
DO_APP_FUNC(0x07201F40, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allEntities, (GameWorld* __this, app::MethodInfo* method));
DO_APP_FUNC(0x07201FA0, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allCharacters, (GameWorld* __this, app::MethodInfo* method));
DO_APP_FUNC(0x07202000, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allInteractives, (GameWorld*, app::MethodInfo* method));
DO_APP_FUNC(0x07202060, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allEnemies, (GameWorld*, app::MethodInfo* method));


DO_APP_FUNC(0x08376310, Camera*, GameUtil_get_mainCamera, ());
DO_APP_FUNC(0x083763A0, app::Entity*, GameUtil_get_mainCharacter, ());
DO_APP_FUNC(0x08376430, Transform*, GameUtil_get_playerTrans, ());
DO_APP_FUNC(0x083764D0, Vector3, GameUtil_get_playerPos, ());

DO_APP_FUNC(0x083E3330, float, AbilitySystemUtils_GetDistance_3, (app::Entity* source, app::Entity* target, app::MethodInfo* method));
DO_APP_FUNC(0x083E2620, Vector3, AbilitySystemUtils_GetPosition, (void*/*AbilitySystem*/* source, app::MethodInfo* method));
DO_APP_FUNC(0x083ACF20, app::ObjectType__Enum, AbilitySystem_get_objectType, (void /*AbilitySystem*/* __this, app::MethodInfo* method));


DO_APP_FUNC(0x00C7E650, app::String*, Entity_get_name, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x00C8BCD0, uint32_t, Entity_get_instanceUid, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x06692780, app::ObjectType__Enum, Entity_get_objectType, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x07357960, app::Vector3, Entity_get_position, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x073616E0, void/*AbilitySystem*/*, Entity_get_abilityCom, (Entity* __this, MethodInfo* method));

DO_APP_FUNC(0x073613C0, void/*ActorController*/*, Entity_get_actorCtrl, (app::Entity* __this, app::MethodInfo* method));
DO_APP_FUNC(0x07341F00, int32_t, ActorController_MoveTo, (void/*ActorController*/* __this, Vector3 targetPosition, bool ignoreUnmovable, app::MethodInfo* method));
DO_APP_FUNC(0x07343BA0, void, ActorController_TeleportToTempFix, (void/*ActorController*/* __this, Vector3 inPos, app::MethodInfo* method));

//pickup
//DO_APP_FUNC(0x07F3F2F0, bool, InteractiveInstigatorControlComponent_SetPickupItem, (InteractiveInstigatorControlComponent* __this, Entity* item, bool ignoreSkillCheck, bool ignoreCheck, /*Nullable_1_UnityEngine_Vector3_*/app::Vector3 sourcePos, app::MethodInfo* method));

//DO_APP_FUNC(0x07F3FB20, void, InteractiveInstigatorControlComponent_PickUp, (InteractiveInstigatorControlComponent* __this, app::MethodInfo* method));


//tp
//DO_APP_FUNC(0x070F2360, void, CharacterController_1_TeleportToWithFx, (CharacterController_1* __this, Vector3 pos, bool playBlinkFx, bool playDissolveFx, app::MethodInfo* method));

//killaura
DO_APP_FUNC(0x07205BB0, void, GameWorld_KillAllEnemies, (GameWorld* __this, app::MethodInfo* method));
DO_APP_FUNC(0x07206CE0, void, GameWorld_HealAllCharacters, (GameWorld* __this, app::MethodInfo* method));
//skill
//DO_APP_FUNC(0x0839EDA0, float, Skill_get_cooldown, (Skill* __this, app::MethodInfo* method));
DO_APP_FUNC(0x083A3240, bool, Skill_CheckCd, (void/*Skill*/* __this, app::MethodInfo* method));
DO_APP_FUNC(0x083A35C0, bool, Skill_CheckCost, (void/*Skill*/* __this, app::MethodInfo* method));



//skip plot
DO_APP_FUNC(0x070C88E0, void, DialogManager__DoPlayDialog, (void/*DialogManager*/* __this, app::MethodInfo* method));
DO_APP_FUNC(0x070CAA10, void, DialogManager__ExitDialog, (void/*DialogManager*/* __this, bool isSkip, app::MethodInfo* method));


//stamina

DO_APP_FUNC(0x00BF5EF0, uint32_t, SC_SYNC_STAMINA_get_CurStamina, (app::SC_SYNC_STAMINA* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x017F6020, CharCurStamina*, Beyond_Gameplay_CharCurStaminaForMemoryPack_GetValue, (Beyond_Gameplay_CharCurStaminaForMemoryPack* __this, app::MethodInfo* method));


//monsterAI

DO_APP_FUNC(0x0812C120, void, EnemyAIBrain_SwitchAIMode, (void/*EnemyAIBrain*/* __this, app::EnemyAIModeType__Enum modeType, bool force, app::MethodInfo* method));


//dither

DO_APP_FUNC(0x082BA2B0, void, EntityRenderHelper_SetDitherAlpha, (void/*EntityRenderHelper*/* __this, float ditherAlpha, int32_t handle, app::MethodInfo* method));

//tp

DO_APP_FUNC(0x08378A50, app::String*, GameUtil_GetCntLevelId, ());
DO_APP_FUNC(0x08378370, int32_t, GameUtil_LevelIdStringToNum, (app::String* levelIdStr));

DO_APP_FUNC(0x07A01C60, void/*GameplayNetwork*/*, GameInstance_get_gameplayNetwork, ());
DO_APP_FUNC(0x07B6F7B0, void, GameplayNetwork_C2STeleport, (void/*GameplayNetwork*/* __this, int32_t levelId, app::TeleportReason__Enum reason, Vector3 position, Vector3 rotationEuler, app::MethodInfo* method));

//DO_APP_FUNC(0x071FD4E0, app::FunctionAreaManager*, GameWorld_get_functionAreaManager, (app::GameWorld* __this,app:: MethodInfo* method));
DO_APP_FUNC(0x07F659D0, void, GameAction_TeleportTeam, (app::Vector3 position, app::Vector3 rotation, app::MethodInfo* method));
//DO_APP_FUNC(0x07F67270, void, GameAction_TeleportTo, (app::String* levelIdStr, app::TeleportReason__Enum reason, app::Vector3 position, app::Vector3 rotationEuler, app::MethodInfo* method));
//DO_APP_FUNC(0x07F67710, void, GameAction_TeleportToPosition, (app::String* sceneId, app::TeleportReason__Enum reason, app::Vector3 pos, app::Quaternion rotation, app::MethodInfo* method));
// 
//custom Profile

DO_APP_FUNC(0x036F4F40, app::String*, UtilsForLua_GetCurrentUID, ());
//UnityEngine.UI.Text$没改
//DO_APP_FUNC(0x022dcc00, void, Text_set_text, (app::Text* __this, app::String* value));
//////UnityEngine.UI.Text$$set_text
//DO_APP_FUNC(0x024DD020, void, Text_set_alignment, (app::Text* __this, app::TextAnchor__Enum value));
//DO_APP_FUNC(0x024DD270, void, Text_set_horizontalOverflow, (app::Text* __this, app::HorizontalWrapMode__Enum value));
//DO_APP_FUNC(0x024DD5A0, void, Text_set_verticalOverflow, (app::Text* __this, app::VerticalWrapMode__Enum value));
//DO_APP_FUNC(0x024DD330, void, Text_set_resizeTextForBestFit, (app::Text* __this, bool value));
//DO_APP_FUNC(0x024DD090, void, Text_set_fontSize, (app::Text* __this, int32_t value));
//UnityEngine.UI.Slider
//DO_APP_FUNC(0x024DA1B0, void, Slider_set_minValue, (app::Slider_1* __this, float value));
//DO_APP_FUNC(0x024D9EA0, void, Slider_set_maxValue, (app::Slider_1* __this, float value));
//DO_APP_FUNC(0x024DA290, void, Slider_set_value, (app::Slider_1* __this, float value));



//System.Runtime.InteropServices.Marshal$$PtrToStringAnsi

DO_APP_FUNC(0x0B2D0140, app::String*, Marshal_PtrToStringAnsi, (void* ptr, app::MethodInfo* method));
DO_APP_FUNC(0x06DC9580, app::String*, I18nUtils_GetText, (app::String* key));
//playerspeed

DO_APP_FUNC(0x0735E800, void/*SelfTimeScaleHandle*/*, Entity_SetSelfTimeScale, (app::Entity* __this, float selfTimeScale, app::MethodInfo* method));
//DO_APP_FUNC(0x0C926250, void, Rigidbody_set_velocity, (void/*Rigidbody*/* __this, app::Vector3 value, MethodInfo* method));
//DO_APP_FUNC(0x0C9261E0, app::Vector3, Rigidbody_get_velocity, (Rigidbody* __this, MethodInfo* method));
//DO_APP_FUNC(0x0C8093B0, float, Animator_get_timeScale, (Animator* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x0C809400, void, Animator_set_timeScale, (Animator* __this, float value, app::MethodInfo* method));
//DO_APP_FUNC(0x0C809460, float, Animator_get_speed, (Animator* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x0C8094B0, void, Animator_set_speed, (Animator* __this, float value, app::MethodInfo* method));

// Game Object, Transform, Object, Component Utility

//public sealed class GameObject :
//UnityEngine.GameObject$$CreatePrimitive
DO_APP_FUNC(0x0C87ED90, GameObject*, GameObject_CreatePrimitive, (PrimitiveType__Enum type, app::MethodInfo* method));
//UnityEngine.GameObject$$get_active
DO_APP_FUNC(0x0C87FC10, bool, GameObject_get_active, (GameObject* __this, app::MethodInfo* method));
//UnityEngine.GameObject$$SetActive
DO_APP_FUNC(0x0C87FCC0, void, GameObject_SetActive, (GameObject* __this, bool value, app::MethodInfo* method));//UnityEngine.GameObject$$Find
DO_APP_FUNC(0x0C880760, GameObject*, GameObject_Find, (String* name, app::MethodInfo* method));

DO_APP_FUNC(0x0C87EF20, Component*, GameObject_GetComponentByName, (GameObject* __this, String* type, app::MethodInfo* method));
//UnityEngine.GameObject$$GetComponentByName
DO_APP_FUNC(0x0C87F9A0, Component*, GameObject_AddComponentInternal, (GameObject* __this, String* className, app::MethodInfo* method));
//UnityEngine.GameObject$$AddComponentInternal

//UnityEngine.GameObject$$get_transform
DO_APP_FUNC(0x0C87FA60, Transform*, GameObject_get_transform, (GameObject* __this, app::MethodInfo* method));



DO_APP_FUNC(0x0C893BE0, Transform*, Transform_GetChild, (Transform* __this, int32_t index, app::MethodInfo* method));
//UnityEngine.Transform$$GetChild

DO_APP_FUNC(0x0C893C40, int32_t, Transform_GetChildCount, (Transform* __this, app::MethodInfo* method));
//UnityEngine.Transform$$GetChildCount

//UnityEngine.Transform$$FindChild
DO_APP_FUNC(0x0C8937D0, Transform*, Transform_FindChild, (Transform* __this, String* n, app::MethodInfo* method));

DO_APP_FUNC(0x0C88FE80, void, Transform_set_localPosition, (Transform * __this, Vector3 value, MethodInfo * method));
DO_APP_FUNC(0x0C88FE10, Vector3, Transform_get_localPosition, (Transform* __this, app::MethodInfo* method));

DO_APP_FUNC(0x0C890F40, void, Transform_set_localRotation, (Transform* __this, Quaternion value, app::MethodInfo* method));
DO_APP_FUNC(0x0C890ED0, Quaternion, Transform_get_localRotation, (Transform* __this, app::MethodInfo* method));



DO_APP_FUNC(0x0C891050, Vector3, Transform_get_localScale, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C8910C0, void, Transform_set_localScale, (Transform * __this, Vector3 value, MethodInfo * method));

DO_APP_FUNC(0x0C890350, Vector3, Transform_get_right, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C8906E0, Vector3, Transform_get_up, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C890A70, Vector3, Transform_get_forward, (Transform * __this, MethodInfo * method));

DO_APP_FUNC(0x0C88FD40, Vector3, Transform_get_position, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C88FDB0, void, Transform_set_position, (Transform * __this, Vector3 value, MethodInfo * method));

DO_APP_FUNC(0x0C890E00, Quaternion, Transform_get_rotation, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C890E70, void, Transform_set_rotation, (Transform * __this, Quaternion value, MethodInfo * method));

DO_APP_FUNC(0x0C891120, Transform *, Transform_get_parent, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C891170, void, Transform_set_parent, (Transform * __this, Transform * value, MethodInfo * method));

DO_APP_FUNC(0x0C890030, Vector3, Transform_get_eulerAngles, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C8900D0, void, Transform_set_eulerAngles, (Transform * __this, Vector3 value, MethodInfo * method));

DO_APP_FUNC(0x0C8901C0, Vector3, Transform_get_localEulerAngles, (Transform * __this, MethodInfo * method));
DO_APP_FUNC(0x0C890260, void, Transform_set_localEulerAngles, (Transform * __this, Vector3 value, MethodInfo * method));


DO_APP_FUNC(0x0C891820, void, Transform_Translate, (app::Transform* __this, app::Vector3 translation));
////UnityEngine.Object$$get_name
DO_APP_FUNC(0x0C884EA0, String *, Object_1_get_name, (Object_1 * __this, MethodInfo * method));
////UnityEngine.Object$$DestroyImmediate
DO_APP_FUNC(0x0C886120, void, Object_1_DestroyImmediate_1, (Object_1 * obj, MethodInfo * method));
////UnityEngine.Component$$get_gameObject
DO_APP_FUNC(0x0AEB1670, GameObject *, Component_get_gameObject, (Component * __this, MethodInfo * method));
DO_APP_FUNC(0x0C885440, Object_1 *, Object_1_Instantiate, (Object_1 * original, Vector3 position, Quaternion rotation, MethodInfo * method));
DO_APP_FUNC(0x0C893500, int32_t, Transform_get_childCount, (Transform* __this, app::MethodInfo* method));
//DO_APP_FUNC(0x0C8A0880,void*/* Scene*/, SceneManager_GetActiveScene, (MethodInfo* method));
//DO_APP_FUNC(0x0C89FE30, void, Scene_GetRootGameObjects_1, (void* __this, List_1_UnityEngine_GameObject_* rootGameObjects, app::MethodInfo* method));
// UnityEngine.RenderSettings$$set_fog
DO_APP_FUNC(0x0C849530, float, RenderSettings_get_fogStartDistance, (MethodInfo * method));
DO_APP_FUNC(0x0C849580, void, RenderSettings_set_fogStartDistance, (float value, MethodInfo * method));
DO_APP_FUNC(0x0C8495E0, float, RenderSettings_get_fogEndDistance, (MethodInfo * method));
DO_APP_FUNC(0x0C849630, void, RenderSettings_set_fogEndDistance, (float value, MethodInfo * method));
DO_APP_FUNC(0x0C849740, float, RenderSettings_get_fogDensity, (MethodInfo * method));
DO_APP_FUNC(0x0C849790, void, RenderSettings_set_fogDensity, (float value, MethodInfo * method));
//public static void set_fog(bool value) { }

//public class Time
DO_APP_FUNC(0x0B6391A0, float, Time_get_deltaTime, (MethodInfo * method));
//public static float get_deltaTime() { }
DO_APP_FUNC(0x0C88BE50, float, Time_get_timeScale, (MethodInfo * method));
//public static float get_timeScale() { }
DO_APP_FUNC(0x0C88BEA0, void, Time_set_timeScale, (float value, MethodInfo * method));


DO_APP_FUNC(0x0C4F5720, bool, Application_get_isFocused, (MethodInfo * method));
//public static bool get_isFocused() { }
DO_APP_FUNC(0x0C822E40, void, Application_set_targetFrameRate, (int32_t value, MethodInfo * method));
//	public static void set_targetFrameRate(int value) { }
DO_APP_FUNC(0x0C842450, void, QualitySettings_set_vSyncCount, (int32_t value, MethodInfo * method));

//UnityEngine.Vector3$$Distance
DO_APP_FUNC(0x0C872A80, float, Vector3_Distance, (Vector3 a, Vector3 b, MethodInfo * method));

DO_APP_FUNC(0x0C871D40, Vector3, Vector3_Lerp, (Vector3 a, Vector3 b, float t, MethodInfo * method));


//public class Cursor

DO_APP_FUNC(0x0C86C3C0, bool, Cursor_get_visible, (MethodInfo * method));
DO_APP_FUNC(0x0C86C410, void, Cursor_set_visible, (bool value, MethodInfo * method));
//public static void set_visible(bool value) { }
DO_APP_FUNC(0x0C86C460, CursorLockMode__Enum, Cursor_get_lockState, (MethodInfo * method));
//public static CursorLockMode get_lockState() { }
DO_APP_FUNC(0x0C86C4B0, void, Cursor_set_lockState, (CursorLockMode__Enum value, MethodInfo * method));
//public static void set_lockState(CursorLockMode value) { }

DO_APP_FUNC(0x0C83C2B0, int32_t, Screen_get_width, (MethodInfo * method));
DO_APP_FUNC(0x0C83C300, int32_t, Screen_get_height, (MethodInfo * method));

//public static int get_height() { }
DO_APP_FUNC(0x0C83CB10, void, Screen_SetResolution, (int32_t width, int32_t height, bool fullscreen, MethodInfo * method));

//camera
DO_APP_FUNC(0x0C82AC40, void, Camera_CopyFrom, (Camera * __this, Camera * other, MethodInfo * method));
DO_APP_FUNC(0x0C829B90, Camera *, Camera_get_main, (MethodInfo * method));
DO_APP_FUNC(0x0C829BE0, Camera *, Camera_get_current, (MethodInfo * method));
DO_APP_FUNC(0x0C826470, float, Camera_get_fieldOfView, (Camera * __this, MethodInfo * method));
DO_APP_FUNC(0x0C8264C0, void, Camera_set_fieldOfView, (Camera * __this, float value, MethodInfo * method));

DO_APP_FUNC(0x0C828E10, Vector3, Camera_WorldToScreenPoint_1, (Camera * __this, Vector3 position, MethodInfo * method));


DO_APP_FUNC(0x00BEE9F0, float, Mathf_Lerp, (float a, float b, float t, MethodInfo * method));
DO_APP_FUNC(0x0C8762B0, float, Mathf_LerpUnclamped, (float a, float b, float t, MethodInfo * method));
DO_APP_FUNC(0x02F52590, float, Mathf_LerpAngle, (float a, float b, float t, MethodInfo * method));
//DO_APP_FUNC(0x0CB82830, float, BaseInput_GetAxisRaw, (BaseInput * __this, String * axisName, MethodInfo * method));
DO_APP_FUNC(0x0C9054A0, float, Input_1_GetAxis, (String* axisName, app::MethodInfo* method));

DO_APP_FUNC(0x0C71CA40, app::String*, TMP_Text_get_text, (void/*TMP_Text*/* __this, MethodInfo* method));
DO_APP_FUNC(0x0C71CB20, void, TMP_Text_set_text, (void/*TMP_Text*/* __this, app::String* value, MethodInfo* method));

// Protection bypass


