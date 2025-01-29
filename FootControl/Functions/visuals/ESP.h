#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
	class ESP : public Function {
	public:
		ConfigField<bool> f_Enabled;
		ConfigField<float> f_Range;
        ConfigField<bool> f_ShowName;
        ConfigField<bool> f_ShowDis;

		ConfigField<bool> f_ShowPlayer;
		ConfigField<bool> f_ShowMonster;
        ConfigField<bool> f_ShowNPC;
        ConfigField<bool> f_ShowItem;

		ConfigField<bool> f_ShowDebug;
		Hotkey f_Hotkey;

		void GUI() override;
		void Outer() override;
		void Status() override;

		std::string getModule() override;

		static ESP& getInstance();

		ESP();
	};
}