#include "trigger.h"

#include "debug.h"

namespace config
{
	namespace trigger
	{
		static const double distance = 2100; // [m]
		static const int wait_time = 20 * 1000; // [ms]
	}

	namespace panel
	{
		namespace index
		{
			static const int output_company = 248;
		};
	};

	namespace details
	{
		namespace index
		{
			static const int sotetsu[] = { 2 };
			static const int jr[] = { 1 };
		};
	};

	namespace company
	{
		static const int sotetsu = 1;
		static const int jr = 2;
	}
}

trigger::trigger() :
	company_(config::company::sotetsu),
	distance_(0),
	door_opened_(false),
	countdown_(0),
	last_time_(0)
{}

void trigger::reset()
{
	this->company_ = config::company::sotetsu;
	this->distance_ = 0;
	this->door_opened_ = false;
	this->countdown_ = 0;
	this->last_time_ = 0;
}

void trigger::set_time(int ms)
{
	const auto dt = ms - this->last_time_;
	this->last_time_ = ms;

	if (this->distance_ < config::trigger::distance)
	{
		return;
	}

	if (!this->door_opened_)
	{
		return;
	}
	if (dt < 0)
	{
		// not expected
		return;
	}

	this->countdown_ -= dt;
	if (this->countdown_ < 0)
	{
		// switching
		this->company_ = config::company::jr;
		this->door_opened_ = false;
	}
}

void trigger::set_distance(double distance)
{
	if (this->distance_ == 0)
	{
		// just after reset
		if (distance > config::trigger::distance)
		{
			this->company_ = config::company::jr;
		}
	}
	this->distance_ = distance;
}

void trigger::set_door_open()
{
	this->door_opened_ = true;
	this->countdown_ = config::trigger::wait_time;
}

void trigger::set_door_close()
{
	this->door_opened_ = false;
}

bool trigger::is_enable(const int detail_index) const
{
	if (this->company_ != config::company::sotetsu)
	{
		for (const auto sotetsu_index : config::details::index::sotetsu)
		{
			if (sotetsu_index == detail_index)
			{
				return false;
			}
		}
	}

	if (this->company_ != config::company::jr)
	{
		for (const auto jr_index : config::details::index::jr)
		{
			if (jr_index == detail_index)
			{
				return false;
			}
		}
	}

	return true;
}

void trigger::output_company(int* p_panel)
{
	// none
	int result = 0;
	if (this->is_enable(config::details::index::sotetsu[0]))
	{
		// sotetsu
		result += 1;
	}
	if (this->is_enable(config::details::index::jr[0]))
	{
		// jr
		result += 2;
	}
	p_panel[config::panel::index::output_company] = result;
}
