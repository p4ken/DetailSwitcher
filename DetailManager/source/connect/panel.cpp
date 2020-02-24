#include "panel.h"

panel::panel(switcher& switcher) :
	switcher_(switcher),
	panels_(nullptr),
	index_input_mascon_key_(-1),
	index_output_state_(-1) {}

void panel::set_setting(const setting& setting)
{
	this->index_input_mascon_key_ = setting.get_panel_index_input_mascon_key();
	this->index_output_state_ = setting.get_panel_index_output_company();
}

void panel::set_panel(int* const p_panel)
{
	this->panels_ = p_panel;
}

void panel::read_panel()
{
	const auto now_input_mascon_key = this->panels_[this->index_input_mascon_key_];
	if (this->last_input_mascon_key_ == 0 && now_input_mascon_key != 0)
	{
		this->switcher_.rise();
	}
	this->last_input_mascon_key_ = now_input_mascon_key;
}


void panel::set_company(const company company) const
{
	this->panels_[this->index_output_state_] = static_cast<int>(company);
}
