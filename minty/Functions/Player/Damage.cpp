#include "Damage.h"

namespace cheat {
   // static void BattleHitReactionManager_Hit_Hook(void/*BattleHitReactionManager*/* __this, app::Entity* attacker, app::String* hitMethodId, float hitValue, bool dontHitImportantInteractive, app::BattleHitReactionManager_HitInfo hitInfo, app::MethodInfo* method);
    //static void/*app::BattleNormalEffect*/* EffectManager_CreateEffectOnTarget_Hook (void/*EffectManager*/* __this, void/*EffectActionCfg*/* effectCfg, void/*app::AbilitySystem*/* target, app::Vector3 dir, void/*ITickOwner*/* timeScaleSource, app::String* overrideName, void /*app::AbilitySystem*/* source);

    Damage::Damage() {
        f_GodMode = config::getValue("functions:Damage", "GodMode", false);
        f_HitMultiplier = config::getValue("functions:Damage", "HitMultiplier", false);
        f_HitMultiplier_Value = config::getValue("functions:Damage", "HitMultiplierValue", 1);

        f_Hotkey = Hotkey("functions:Damage");

        //HookManager::install(app::BattleHitReactionManager_Hit, BattleHitReactionManager_Hit_Hook);
      //  HookManager::install(app::EffectManager_CreateEffectOnTarget, EffectManager_CreateEffectOnTarget_Hook);
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


    //void BattleHitReactionManager_Hit_Hook(void/*BattleHitReactionManager*/* __this, app::Entity* attacker, app::String* hitMethodId, float hitValue, bool dontHitImportantInteractive, app::BattleHitReactionManager_HitInfo hitInfo, app::MethodInfo* method) {
    //    LOG_DEBUG("BattleHitReactionManager_Hit_Hook hitValue:%f ", hitValue);
    //    LOG_DEBUG("BattleHitReactionManager_Hit_Hook attacker:%s ", il2cppi_to_string(attacker->fields._name_k__BackingField).c_str());

    //    return;
    ////    auto& Damage = Damage::getInstance();
    ////    auto attackerenum= app::Entity_get_objectType(attacker, nullptr);
    ////    if (Damage.f_GodMode&& attackerenum == app::ObjectType__Enum::ObjectType__Enum_Enemy) {
    ////        return;
    ////       // hitValue = 0;
    ////    }
    ////    if (Damage.f_HitMultiplier&& attackerenum == app::ObjectType__Enum::ObjectType__Enum_Character) {
    ////        //hitValue *= Damage.f_HitMultiplier_Value;
    ////        for (int i = 0; i < Damage.f_HitMultiplier_Value.getValue(); i++) {
    ////            CALL_ORIGIN(BattleHitReactionManager_Hit_Hook, __this, attacker, hitMethodId, hitValue, dontHitImportantInteractive, hitInfo, method);
    ////        }
    ////            
    ////        return;
    ////    }
    ////    return CALL_ORIGIN(BattleHitReactionManager_Hit_Hook, __this, attacker, hitMethodId, hitValue, dontHitImportantInteractive, hitInfo, method);
    //}
    //void/*app::BattleNormalEffect*/* EffectManager_CreateEffectOnTarget_Hook(void/*EffectManager*/* __this, void/*EffectActionCfg*/* effectCfg, void/*app::AbilitySystem*/* target, app::Vector3 dir, void/*ITickOwner*/* timeScaleSource, app::String* overrideName, void /*app::AbilitySystem*/* source) {
    //
    //    auto& Damage = Damage::getInstance();
    //    auto sourceAb = app::AbilitySystem_get_objectType(source,nullptr);
    //    if( Damage.f_GodMode.getValue() && sourceAb == app::ObjectType__Enum::ObjectType__Enum_Enemy) {
    //        return nullptr;
    //    }
    //    return CALL_ORIGIN(EffectManager_CreateEffectOnTarget_Hook, __this, effectCfg, target, dir, timeScaleSource, overrideName, source);
    //}
}
