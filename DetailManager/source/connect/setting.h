#pragma once

#include <string>
#include <vector>
#include <memory>


class setting
{
public:
	void set_module_directory(const wchar_t* module_dir);
	
	int get_state_output_panel_index() const {
		return 252;
	}

	std::vector<std::string> get_detail_paths() const
	{
		return { "Rock_On\\ATSN.dll", "unicorn\\ATS_SO.dll", "bvews\\BvetsStatusWindow.dll" };
	}
};

using setting_ptr = std::shared_ptr<setting>;
