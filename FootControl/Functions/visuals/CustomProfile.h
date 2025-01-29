#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
	class CustomProfile : public Function {
	public:
		ConfigField<bool> f_Enabled;
		ConfigField < std::string > f_UIDtext;

		Hotkey f_Hotkey;

		void GUI() override;
		void Outer() override;
		void Status() override;

		std::string getModule() override;

		static CustomProfile& getInstance();

		CustomProfile();
	};
}
