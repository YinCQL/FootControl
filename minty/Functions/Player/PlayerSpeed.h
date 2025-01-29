#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
	class PlayerSpeed : public Function {
	public:
		ConfigField<bool> f_Enabled;
		ConfigField<float> f_Speed;
		Hotkey f_Hotkey;

		void GUI() override;
		void Outer() override;
		void Status() override;

		std::string getModule() override;

		static PlayerSpeed& getInstance();

		PlayerSpeed();
	};
}