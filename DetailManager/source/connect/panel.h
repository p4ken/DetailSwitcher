#pragma once
#include <vector>

#include "setting.h"

class Panel {
public:
	enum class company
	{
		sotetsu = 1,
		jr = 2,
	};

public:
	explicit Panel(const Setting& setting) : setting_(setting), panels_() {}
	virtual ~Panel() = default;

public:
	void set_panel(int* const p_panel)
	{
		this->panels_ = p_panel;
	}

	void set_company(const company company) const
	{
		const auto index = this->setting_.GetStateOutputPanelIndex();
		this->panels_[index] = static_cast<int>(company);
	}

private:
	const Setting& setting_;
	int* panels_;
};