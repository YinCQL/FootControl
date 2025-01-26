#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
	class Damage : public Function {
	public:
		ConfigField<bool> f_GodMode;
		ConfigField<bool> f_HitMultiplier;
		ConfigField<int> f_HitMultiplier_Value;
		Hotkey f_Hotkey;

		void GUI() override;
		void Outer() override;
		void Status() override;

		std::string getModule() override;

		static Damage& getInstance();

		Damage();
	};
}