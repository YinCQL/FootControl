#include "Damage.h"

namespace cheat {
    static void BattleHitReactionManager_Hit_Hook(void/*BattleHitReactionManager*/* __this, app::Entity* attacker, app::String* hitMethodId, float hitValue, bool dontHitImportantInteractive, app::BattleHitReactionManager_HitInfo hitInfo, app::MethodInfo* method);


    Damage::Damage() {
        f_GodMode = config::getValue("functions:Damage", "GodMode", false);
        f_HitMultiplier = config::getValue("functions:Damage", "HitMultiplier", false);
        f_HitMultiplier_Value = config::getValue("functions:Damage", "HitMultiplierValue", 1);

        f_Hotkey = Hotkey("functions:Damage");

        HookManager::install(app::BattleHitReactionManager_Hit, BattleHitReactionManager_Hit_Hook);

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
        return _("MODULE_PLAYER");
    }

    //void VCHumanoidMove_NotifyLandVelocity_Hook(app::VCHumanoidMove* __this, app::Vector3 velocity,
    //    float reachMaxDownVelocityTime) {
    //    auto& Damage = Damage::getInstance();

    //    if (Damage.f_Enabled && -velocity.y > 13) {
    //        float randAdd = (float)(std::rand() % 1000) / 1000;
    //        velocity.y = -8 - randAdd;
    //        reachMaxDownVelocityTime = 0;
    //    }
    //    CALL_ORIGIN(VCHumanoidMove_NotifyLandVelocity_Hook, __this, velocity, reachMaxDownVelocityTime);
    //}
    void BattleHitReactionManager_Hit_Hook(void/*BattleHitReactionManager*/* __this, app::Entity* attacker, app::String* hitMethodId, float hitValue, bool dontHitImportantInteractive, app::BattleHitReactionManager_HitInfo hitInfo, app::MethodInfo* method) {
        auto& Damage = Damage::getInstance();
        auto attackerenum= app::Entity_get_objectType(attacker, nullptr);
        if (Damage.f_GodMode&& attackerenum == app::ObjectType__Enum::ObjectType__Enum_Enemy) {
            return;
           // hitValue = 0;
        }
        if (Damage.f_HitMultiplier&& attackerenum == app::ObjectType__Enum::ObjectType__Enum_Character) {
            //hitValue *= Damage.f_HitMultiplier_Value;
            for (int i = 0; i < Damage.f_HitMultiplier_Value.getValue(); i++) {
                CALL_ORIGIN(BattleHitReactionManager_Hit_Hook, __this, attacker, hitMethodId, hitValue, dontHitImportantInteractive, hitInfo, method);
            }
                
            return;
        }
        return CALL_ORIGIN(BattleHitReactionManager_Hit_Hook, __this, attacker, hitMethodId, hitValue, dontHitImportantInteractive, hitInfo, method);
    }

}
