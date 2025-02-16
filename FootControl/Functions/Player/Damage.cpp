#include "Damage.h"

namespace cheat {

    static void/*app::BattleNormalEffect*/* EffectManager_CreateEffectOnTarget_Hook (void/*EffectManager*/* __this, void/*EffectActionCfg*/* effectCfg, void/*app::AbilitySystem*/* target, app::Vector3 dir, void/*ITickOwner*/* timeScaleSource, app::String* overrideName, void /*app::AbilitySystem*/* source);
    static app::AbilitySystem_Modifier AbilitySystem_Modifier_NewDamage_Hook(void /*AbilitySystem*/* source, void /*AbilitySystem*/* target, double value, app::DamageType__Enum damageType, app::DamageDecorateMask__Enum damageDecorateMask, app::AbilitySystem_Modifier_DamageVisualImportance__Enum damageVisualImportance, bool isCritical, app::String* damageSourceId, void/*AbilitySystem_Modifier_DamageVisualCoalition*/* damageVisualCoalition, app::Nullable_1_UnityEngine_Vector3_ hitPoint, bool hideMainCharHpScreenEffect, app::MethodInfo* method);

    Damage::Damage() {
        f_GodMode = config::getValue("functions:Damage", "GodMode", false);
        f_HitMultiplier = config::getValue("functions:Damage", "HitMultiplier", false);
        f_HitMultiplier_Value = config::getValue("functions:Damage", "HitMultiplierValue", 1);

        f_Hotkey = Hotkey("functions:Damage");
      //  HookManager::install(app::AbilitySystem_Modifier_NewDamage, AbilitySystem_Modifier_NewDamage_Hook);
       // HookManager::install(app::EffectManager_CreateEffectOnTarget, EffectManager_CreateEffectOnTarget_Hook);

    }

    Damage& Damage::getInstance() {
        static Damage instance;
        return instance;
    }

    void Damage::GUI() {
        if (ConfigCheckbox(_("GodMode"), f_GodMode, _("GodMode"))) {
            //ImGui::Indent();
            //f_Hotkey.Draw();
            //ImGui::Unindent();
        }
        if (ConfigCheckbox(_("HitMultiplier"), f_HitMultiplier, _("HitMultiplier"))) {
            ImGui::Indent();
            ConfigDragInt("HitMultiplierValue", f_HitMultiplier_Value, 1, 1, 50);
            ImGui::Unindent();
        }
    }

    void Damage::Outer() {
        //if (f_Hotkey.IsPressed())
        //{
        //    f_Enabled.setValue(!f_Enabled.getValue());
        //}
    }

    void Damage::Status() {
        if (f_GodMode)
            ImGui::Text(_("GodMode"));
        if (f_HitMultiplier)
            ImGui::Text(_("HitMultiplier"));
    }

    std::string Damage::getModule() {
        return _("Player");
    }

   //app::AbilitySystem_Modifier AbilitySystem_Modifier_NewDamage_Hook(void /*AbilitySystem*/* source, void /*AbilitySystem*/* target, double value, app::DamageType__Enum damageType, app::DamageDecorateMask__Enum damageDecorateMask, app::AbilitySystem_Modifier_DamageVisualImportance__Enum damageVisualImportance, bool isCritical, app::String* damageSourceId, void/*AbilitySystem_Modifier_DamageVisualCoalition*/* damageVisualCoalition, app::Nullable_1_UnityEngine_Vector3_ hitPoint, bool hideMainCharHpScreenEffect, app::MethodInfo* method) {
   //    LOG_DEBUG("AbilitySystem_Modifier_NewDamage_Hook");
   //     //return CALL_ORIGIN(AbilitySystem_Modifier_NewDamage_Hook, source, target, double(9999999) ,damageType, damageDecorateMask, damageVisualImportance, isCritical, damageSourceId, damageVisualCoalition, hitPoint, hideMainCharHpScreenEffect, method);
   //     return CALL_ORIGIN(AbilitySystem_Modifier_NewDamage_Hook, source, target, value, damageType, damageDecorateMask, damageVisualImportance, isCritical, damageSourceId, damageVisualCoalition, hitPoint, hideMainCharHpScreenEffect, method);
  //  }

   void* EffectManager_CreateEffectOnTarget_Hook (void/*EffectManager*/* __this, void/*EffectActionCfg*/* effectCfg, void/*app::AbilitySystem*/* target, app::Vector3 dir, void/*ITickOwner*/* timeScaleSource, app::String* overrideName, void /*app::AbilitySystem*/* source) {
       auto tar = app::AbilitySystem_get_objectType(target,nullptr);
       auto sou = app::AbilitySystem_get_objectType(source, nullptr);
       if ( sou == app::ObjectType__Enum::ObjectType__Enum_Enemy&& tar == app::ObjectType__Enum::ObjectType__Enum_Character) {
           LOG_DEBUG("sou :Enemy tar chara");    
           return nullptr;
       }
       if (sou == app::ObjectType__Enum::ObjectType__Enum_Enemy && tar == app::ObjectType__Enum::ObjectType__Enum_Enemy) {
           LOG_DEBUG("sou :Enemy ");
           return nullptr;
       }


       return CALL_ORIGIN(EffectManager_CreateEffectOnTarget_Hook, __this, effectCfg, target, dir, timeScaleSource, overrideName, source);
   }
}
