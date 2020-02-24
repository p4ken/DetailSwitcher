#pragma once

#include <string>
#include <vector>
#include <memory>

class setting
{
public:
	// 自分自身のdllがあるフォルダの絶対パス
	void set_module_directory(const wchar_t* module_dir);

	// 会社切替状態を出力するパネルインデックス
	int get_panel_index_output_company() const;

	// マスコンキーが入力されるパネルインデックス
	int get_panel_index_input_mascon_key() const;

	// トリガーになる地上子のType
	int get_beacon_type() const;

	// DLLのパス
	std::vector<std::string> get_detail_paths() const;
};

using setting_ptr = std::shared_ptr<setting>;
