#include "il2cpp-types.h"
//#include "il2cpp-enum.h"


using namespace app;


//globalupdate
//UnityEngine.EventSystems.EventSystem$$Update
//DO_APP_FUNC(0x024E4CF0,  void, EventSystem_Update, ( app::EventSystem* __this, app::MethodInfo* method));
DO_APP_FUNC(0x03373CB0, void, GameApp_Update, (void* __this));



//damage

//DO_APP_FUNC(0x07C5BF20, app::BattleNormalEffect*, EffectManager_CreateEffectOnTarget, (void/*EffectManager*/* __this, void/*EffectActionCfg*/* effectCfg, app::AbilitySystem* target, Vector3 dir, void/*ITickOwner*/* timeScaleSource, String* overrideName, app::AbilitySystem* source, MethodInfo* method));

//DO_APP_FUNC(0x07061FB0, bool, BattleHitReactionManager_TryGetHitInfo, (BattleHitReactionManager* __this, ECSColliderResultProxy collider, Vector3 hitPoint, BattleHitReactionManager_HitInfo* hitInfo, MethodInfo* method));

//DO_APP_FUNC(0x083DA6C0, AbilitySystem_Modifier, AbilitySystem_Modifier_NewDamage, (AbilitySystem* source, AbilitySystem* target, double value, DamageType__Enum damageType, DamageDecorateMask__Enum damageDecorateMask, AbilitySystem_Modifier_DamageVisualImportance__Enum damageVisualImportance, bool isCritical, String* damageSourceId, AbilitySystem_Modifier_DamageVisualCoalition* damageVisualCoalition, Nullable_1_UnityEngine_Vector3_ hitPoint, bool hideMainCharHpScreenEffect, MethodInfo* method));
//DO_APP_FUNC(0x083DAA30, AbilitySystem_Modifier, AbilitySystem_Modifier_NewDamage_1, (AbilitySystem* source, AbilitySystem* target, double value, DamageType__Enum damageType, DamageDecorateMask__Enum damageDecorateMask, AbilitySystem_Modifier_DamageVisualImportance__Enum damageVisualImportance, bool isCritical, MethodInfo* method));
//DO_APP_FUNC(0x083DAC20, AbilitySystem_Modifier, AbilitySystem_Modifier_NewHeal, (AbilitySystem* source, AbilitySystem* target, double value, bool showText, MethodInfo* method));
//DO_APP_FUNC(0x083DAD30, AbilitySystem_Modifier, AbilitySystem_Modifier_NewHeal_1, (AbilitySystem* source, AbilitySystem* target, double value, bool showText, bool createBuff, MethodInfo* method));
DO_APP_FUNC(0x07062390, void, BattleHitReactionManager_Hit, (void/*BattleHitReactionManager*/* __this, app::Entity* attacker, app::String* hitMethodId, float hitValue, bool dontHitImportantInteractive, app::BattleHitReactionManager_HitInfo hitInfo, MethodInfo* method));

//entity
DO_APP_FUNC(0x07A01760, GameWorld*, GameInstance_get_world, (MethodInfo* method));
//DO_APP_FUNC(0x07404B50, void, SceneGridContext_GetEntityList, (void/*SceneGridContext*/* __this, Vector3 pos, float radius, EEntityType__Enum entityType, List_1_Beyond_ObjectPtr_1__4* target, MethodInfo* method));
DO_APP_FUNC(0x07201F40, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allEntities, (GameWorld* __this, MethodInfo* method));
DO_APP_FUNC(0x07201FA0, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allCharacters, (GameWorld* __this, MethodInfo* method));
DO_APP_FUNC(0x07202000, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allInteractives, (GameWorld*, MethodInfo* method));
DO_APP_FUNC(0x07202060, UnorderedArray_1_ObjectPtr_1_Beyond_Gameplay_Core_Entity_*, GameWorld_get_allEnemies, (GameWorld*, MethodInfo* method));


DO_APP_FUNC(0x08376310, Camera*, GameUtil_get_mainCamera, ());
DO_APP_FUNC(0x083763A0, app::Entity*, GameUtil_get_mainCharacter, ());
DO_APP_FUNC(0x08376430, Transform*, GameUtil_get_playerTrans, ());
DO_APP_FUNC(0x083764D0, Vector3, GameUtil_get_playerPos, ());

DO_APP_FUNC(0x083E3330, float, AbilitySystemUtils_GetDistance_3, (app::Entity* source, app::Entity* target, MethodInfo* method));
DO_APP_FUNC(0x083E2620, Vector3, AbilitySystemUtils_GetPosition, (void*/*AbilitySystem*/* source, MethodInfo* method));

DO_APP_FUNC(0x00C7E650, String*, Entity_get_name, (app::Entity* __this, MethodInfo* method));
DO_APP_FUNC(0x00C8BCD0, uint32_t, Entity_get_instanceUid, (app::Entity* __this, MethodInfo* method));
DO_APP_FUNC(0x06692780, app::ObjectType__Enum, Entity_get_objectType, (app::Entity* __this, MethodInfo* method));
DO_APP_FUNC(0x07357960, app::Vector3, Entity_get_position, (app::Entity* __this, MethodInfo* method));

DO_APP_FUNC(0x073613C0, void/*ActorController*/*, Entity_get_actorCtrl, (app::Entity* __this, MethodInfo* method));
DO_APP_FUNC(0x07341F00, int32_t, ActorController_MoveTo, (void/*ActorController*/* __this, Vector3 targetPosition, bool ignoreUnmovable, MethodInfo* method));
DO_APP_FUNC(0x07343BA0, void, ActorController_TeleportToTempFix, (void/*ActorController*/* __this, Vector3 inPos, MethodInfo* method));

//pickup
//DO_APP_FUNC(0x07F3F2F0, bool, InteractiveInstigatorControlComponent_SetPickupItem, (InteractiveInstigatorControlComponent* __this, Entity* item, bool ignoreSkillCheck, bool ignoreCheck, /*Nullable_1_UnityEngine_Vector3_*/app::Vector3 sourcePos, MethodInfo* method));

//DO_APP_FUNC(0x07F3FB20, void, InteractiveInstigatorControlComponent_PickUp, (InteractiveInstigatorControlComponent* __this, MethodInfo* method));


//tp
//DO_APP_FUNC(0x070F2360, void, CharacterController_1_TeleportToWithFx, (CharacterController_1* __this, Vector3 pos, bool playBlinkFx, bool playDissolveFx, MethodInfo* method));

//killaura
DO_APP_FUNC(0x07205BB0, void, GameWorld_KillAllEnemies, (GameWorld* __this, MethodInfo* method));
DO_APP_FUNC(0x07206CE0, void, GameWorld_HealAllCharacters, (GameWorld* __this, MethodInfo* method));
//skill
//DO_APP_FUNC(0x0839EDA0, float, Skill_get_cooldown, (Skill* __this, MethodInfo* method));
DO_APP_FUNC(0x083A3240, bool, Skill_CheckCd, (void/*Skill*/* __this, MethodInfo* method));
DO_APP_FUNC(0x083A35C0, bool, Skill_CheckCost, (void/*Skill*/* __this, MethodInfo* method));

/*DO_APP_FUNC(0x08475F00, DamagePackData, DamagePackData_Create, (DamageType__Enum damageType, DamageDecorateMask__Enum damageDecorateMask, AbilitySystem* attacker, AbilitySystem* defender, MethodInfo* method))*/;


//skip plot
DO_APP_FUNC(0x070C88E0, void, DialogManager__DoPlayDialog, (void/*DialogManager*/* __this, MethodInfo* method));
DO_APP_FUNC(0x070CAA10, void, DialogManager__ExitDialog, (void/*DialogManager*/* __this, bool isSkip, MethodInfo* method));


//stamina

DO_APP_FUNC(0x00BF5EF0, uint32_t, SC_SYNC_STAMINA_get_CurStamina, (app::SC_SYNC_STAMINA* __this, MethodInfo* method));
//DO_APP_FUNC(0x017F6020, CharCurStamina*, Beyond_Gameplay_CharCurStaminaForMemoryPack_GetValue, (Beyond_Gameplay_CharCurStaminaForMemoryPack* __this, MethodInfo* method));


//monsterAI

DO_APP_FUNC(0x0812C120, void, EnemyAIBrain_SwitchAIMode, (void/*EnemyAIBrain*/* __this, app::EnemyAIModeType__Enum modeType, bool force, MethodInfo* method));


//dither
DO_APP_FUNC(0x0B6FB6E0, bool, EntityRenderAlphaDitherController_SetDitherAlpha, (void*/*EntityRenderAlphaDitherController*/* __this, float alpha, int32_t handle, MethodInfo* method));


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

DO_APP_FUNC(0x0B2D0140, app::String*, Marshal_PtrToStringAnsi, (void* ptr, MethodInfo* method));

//playerspeed

DO_APP_FUNC(0x0735E800, void/*SelfTimeScaleHandle*/*, Entity_SetSelfTimeScale, (app::Entity* __this, float selfTimeScale, MethodInfo* method));
//DO_APP_FUNC(0x0C8093B0, float, Animator_get_timeScale, (Animator* __this, MethodInfo* method));
//DO_APP_FUNC(0x0C809400, void, Animator_set_timeScale, (Animator* __this, float value, MethodInfo* method));
//DO_APP_FUNC(0x0C809460, float, Animator_get_speed, (Animator* __this, MethodInfo* method));
//DO_APP_FUNC(0x0C8094B0, void, Animator_set_speed, (Animator* __this, float value, MethodInfo* method));

// Game Object, Transform, Object, Component Utility

//public sealed class GameObject :
//UnityEngine.GameObject$$CreatePrimitive
DO_APP_FUNC(0x0C87ED90, GameObject*, GameObject_CreatePrimitive, (PrimitiveType__Enum type, MethodInfo* method));
//UnityEngine.GameObject$$get_active
DO_APP_FUNC(0x0C87FC10, bool, GameObject_get_active, (GameObject* __this, MethodInfo* method));
//UnityEngine.GameObject$$SetActive
DO_APP_FUNC(0x0C87FCC0, void, GameObject_SetActive, (GameObject* __this, bool value, MethodInfo* method));//UnityEngine.GameObject$$Find
DO_APP_FUNC(0x0C880760, GameObject*, GameObject_Find, (String* name, MethodInfo* method));

DO_APP_FUNC(0x0C87EF20, Component*, GameObject_GetComponentByName, (GameObject* __this, String* type, MethodInfo* method));
//UnityEngine.GameObject$$GetComponentByName
DO_APP_FUNC(0x0C87F9A0, Component*, GameObject_AddComponentInternal, (GameObject* __this, String* className, MethodInfo* method));
//UnityEngine.GameObject$$AddComponentInternal

//UnityEngine.GameObject$$get_transform
DO_APP_FUNC(0x0C87FA60, Transform*, GameObject_get_transform, (GameObject* __this, MethodInfo* method));



DO_APP_FUNC(0x0C893BE0, Transform*, Transform_GetChild, (Transform* __this, int32_t index, MethodInfo* method));
//UnityEngine.Transform$$GetChild

DO_APP_FUNC(0x0C893C40, int32_t, Transform_GetChildCount, (Transform* __this, MethodInfo* method));
//UnityEngine.Transform$$GetChildCount

//UnityEngine.Transform$$FindChild
DO_APP_FUNC(0x0C8937D0, Transform*, Transform_FindChild, (Transform* __this, String* n, MethodInfo* method));

DO_APP_FUNC(0x0C88FE80, void, Transform_set_localPosition, (Transform * __this, Vector3 value, MethodInfo * method));
DO_APP_FUNC(0x0C88FE10, Vector3, Transform_get_localPosition, (Transform* __this, MethodInfo* method));

DO_APP_FUNC(0x0C890F40, void, Transform_set_localRotation, (Transform* __this, Quaternion value, MethodInfo* method));
DO_APP_FUNC(0x0C890ED0, Quaternion, Transform_get_localRotation, (Transform* __this, MethodInfo* method));



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
DO_APP_FUNC(0x0CB82830, float, BaseInput_GetAxisRaw, (BaseInput * __this, String * axisName, MethodInfo * method));




// Protection bypass


