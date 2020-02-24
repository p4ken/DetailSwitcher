#pragma once
#include "connect/setting.h"
#include "detail/switcher.h"

class beacon
{
public:
	explicit beacon(switcher& switcher);
	
	enum class command
	{
		enable_when_rise = 1, // 次回マスコンキー立ち上がりで有効
		disable_when_rise = 2, // 次回マスコンキー立ち上がりで無効
		enable_immediately = 5, // 即時有効
		disable_immediately = 6, // 即時無効
	};

	void set_setting(const setting& setting);

	void set_beacon(int type, int option) const;

private:
	switcher& switcher_;
	int beacon_type_;
};
