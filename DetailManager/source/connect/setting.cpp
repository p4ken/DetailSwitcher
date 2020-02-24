#include "setting.h"

#include <windows.h>
#include "logger.h"

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
	bool file_exists = _wstat(full_path.c_str(), &buf) == 0;
	if (!file_exists)
	{
		logger::get_logger().write_error("setting file does not exits.");
		return;
	}
}

std::vector<std::string> setting::get_detail_paths() const
{
	return { "Rock_On\\ATSN.dll", "unicorn\\ATS_SO.dll", "bvews\\BvetsStatusWindow.dll" };
}
