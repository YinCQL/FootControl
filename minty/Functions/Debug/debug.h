#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
    class Debug : public Function {
    public:




	Hotkey f_Resolution;
	ConfigField<int> f_Resolutionwidth;
	ConfigField<int> f_Resolutionheight;
	ConfigField<bool> f_Resolutionfullscreen;
	ConfigField<bool> f_UIInspector;

	void GUI() override;
	void Outer() override;
	void Status() override;

	void SetResolution();


	std::string getModule() override;

	static Debug& getInstance();

	Debug();
    };
}
