#include "trigger.h"

namespace
{
	struct config
	{
		struct panel
		{
			static const int output_company = 248;
		};
	};
}

void trigger::set_time(int ms)
{
	// todo
}

void trigger::set_distance(double distance)
{
	// todo
}

void trigger::set_door_open()
{
	// todo
}

bool trigger::is_enable(int detail_index)
{
	return detail_index != 1;
}

void trigger::output_company(int* p_panel)
{
	// none
	int result = 0;
	if (this->is_enable(2))
	{
		// sotetsu
		result += 1;
	}
	if (this->is_enable(1))
	{
		// jr
		result += 2;
	}
	p_panel[config::panel::output_company] = result;
}
