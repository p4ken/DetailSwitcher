#include "trigger.h"

#include "ats_define.hpp"
#include "debug.h"

namespace config
{
	namespace trigger
	{
		const double distance = 2100; // [m]
		const int wait_time = 35 * 1000; // [ms]
	}

	namespace panel
	{
		namespace index
		{
			const int output_company = 246;
		};
	};

	namespace sound
	{
		namespace index
		{
			const int announce_here = 21;
		};
	};

	namespace details
	{
		namespace index
		{
			const int sotetsu[] = { 2, 5 };
			const int jr[] = { 3 };
		};
	};

	namespace company
	{
		const int sotetsu = 1;
		const int jr = 2;
	}
}

trigger::trigger() :
	company_(config::company::sotetsu),
	distance_(0),
	door_opened_(false),
	countdown_(0),
	last_time_(0),
	announce_here_(false),
	announce_reset_(false)
{}

void trigger::reset()
{
	this->company_ = config::company::sotetsu;
	this->distance_ = 0;
	this->door_opened_ = false;
	this->countdown_ = 0;
	this->last_time_ = 0;
	this->announce_here_ = false;
	this->announce_reset_ = true;
}

void trigger::set_time(const int ms)
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
	if (this->countdown_ < 0 && this->company_ != config::company::jr)
	{
		// switching
		this->company_ = config::company::jr;
		this->door_opened_ = false;
		this->announce_here_ = true;
	}
}

void trigger::set_distance(const double distance)
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

void trigger::output_company(int* p_panel) const
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

void trigger::announce_here(int* p_sound)
{
	if (this->announce_reset_)
	{
		p_sound[config::sound::index::announce_here] = ATS_SOUND_STOP;
		this->announce_reset_ = false;
		return;
	}
	if (this->announce_here_)
	{
		p_sound[config::sound::index::announce_here] = ATS_SOUND_PLAY;
		this->announce_here_ = false;
		return;
	}
	p_sound[config::sound::index::announce_here] = ATS_SOUND_CONTINUE;
}
