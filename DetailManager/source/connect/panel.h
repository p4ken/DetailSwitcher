#pragma once
#include <vector>

#include "setting.h"

class panel {
public:
	enum class company
	{
		sotetsu = 1,
		jr = 2,
	};

public:
	explicit panel() : panels_(nullptr){}
	virtual ~panel() = default;

public:
	void set_setting(const setting& setting)
	{
		this->index_output_state_ = setting.get_state_output_panel_index();
	}

	void set_panel(int* const p_panel)
	{
		this->panels_ = p_panel;
	}

	void set_company(const company company) const
	{
		this->panels_[this->index_output_state_] = static_cast<int>(company);
	}

private:
	int* panels_;
	int index_output_state_;
};
