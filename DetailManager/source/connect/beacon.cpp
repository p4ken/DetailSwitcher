#include "beacon.h"

#include "connect/logger.h"

beacon::beacon(switcher& switcher) : switcher_(switcher), beacon_type_(-1) {}

void beacon::set_setting(const setting& setting)
{
	this->beacon_type_ = setting.get_beacon_type();
}

void beacon::set_beacon(int type, int option) const
{
	if (type == this->beacon_type_)
	{
		const auto command = static_cast<beacon::command>(option / 100 % 10);
		const int detail_index = option % 10;

		switch(command)
		{
		case command::enable_immediately:
			this->switcher_.enable(detail_index);
			break;
		case command::disable_immediately:
			this->switcher_.disable(detail_index);
			break;
		case command::enable_when_rise:
			this->switcher_.enable_when_rise(detail_index);
			break;
		case command::disable_when_rise:
			this->switcher_.disable_when_rise(detail_index);
			break;
		case command::trial:
			this->switcher_.fall();
			break;
		default:
			break;
		}
	}
}

