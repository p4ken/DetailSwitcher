#pragma once

#include <string>
#include <vector>
#include <memory>


class setting
{
public:
	// 自分自身のDLLの絶対パス
	void set_module_directory(const wchar_t* module_dir);

	// 選択状態の出力に使うパネルの添字
	int get_state_output_panel_index() const;

	// 切替のトリガーになる地上子の種類
	int get_beacon_type() const;

	// DLLへのパス
	std::vector<std::string> get_detail_paths() const;
};

using setting_ptr = std::shared_ptr<setting>;
