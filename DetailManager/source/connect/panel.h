#pragma once
#include <vector>

#include "connect/setting.h"
#include "detail/switcher.h"

class panel {
public:
	enum class company
	{
		sotetsu = 1,
		jr = 2,
	};

	//　コンストラクタ
	explicit panel(switcher& switcher);

	// 設定
	void set_setting(const setting& setting);

	// パネルのポインタ
	void set_panel(int* const p_panel);

	// パネル読み取り
	void read_panel();

	// 会社切替状態
	void set_company(const company company) const;

private:
	switcher& switcher_;
	int* panels_;
	int index_input_mascon_key_;
	int last_input_mascon_key_;
	int index_output_state_;
};
