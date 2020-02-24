#include "beacon.h"

#include "source/connect/logger.h"

beacon::beacon(switcher& switcher) : switcher_(switcher), beacon_type_(-1) {}

void beacon::set_setting(const setting& setting)
{
	this->beacon_type_ = setting.get_beacon_type();
}

void beacon::set_beacon(int type, int option)
{
	if (type == this->beacon_type_)
	{
		const auto command = static_cast<beacon::command>(option / 100 % 10);
		const int detail_index = option % 10;

		if (command == command::enable_immediately)
		{
			this->switcher_.enable(detail_index);
			logger::get_logger().write_debug("set_beacon(" + std::to_string(detail_index) + ") : enabled immediately.");
		}
	}
}

