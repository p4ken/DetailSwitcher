#pragma once

#include <string>
#include <vector>

namespace
{
	static const std::string setting_file_path("DetailSelector.ini");
}

class Setting
{
public:
	Setting() {}
	virtual ~Setting() {}

public:
	int GetStateOutputPanelIndex() const {
		return 252;
	}
};
