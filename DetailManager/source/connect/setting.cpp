#include "setting.h"

#include <windows.h>
#include "connect/logger.h"

namespace
{
	static const std::wstring file_name(L"DetailSelector.ini");
}

void setting::set_module_directory(const wchar_t* module_dir)
{
	std::wstring full_path(module_dir);
	full_path.append(file_name);
	// MessageBox(NULL, full_path.c_str(), TEXT("debug"), MB_OK);
	logger::get_logger().write_debug("set module directory.");

	struct _stat buf;
	const bool file_exists = _wstat(full_path.c_str(), &buf) == 0;
	if (!file_exists)
	{
		logger::get_logger().write_error("setting file does not exits.");
		return;
	}
}

int setting::get_panel_index_output_company() const
{
	return 252;
}

int setting::get_panel_index_input_mascon_key() const
{
	return 247;
}

int setting::get_beacon_type() const
{
	return 26;
}

std::vector<std::string> setting::get_detail_paths() const
{
	return { "Rock_On\\ATSN.dll", "unicorn\\ATS_SO.dll", "bvews\\BvetsStatusWindow.dll" };
}
