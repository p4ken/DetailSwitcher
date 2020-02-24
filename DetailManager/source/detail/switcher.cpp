#include "switcher.h"

#include <string>

#include "source/connect/logger.h"

switcher::switcher() : enables_(100, false) {}

void switcher::enable(int detail_index)
{
	this->enables_.at(detail_index) = true;
}

void switcher::enable_when_rise(int detail_index)
{
	this->waiting_enable_.push(detail_index);
}

void switcher::rise()
{
	while(!this->waiting_enable_.empty())
	{
		const auto index = this->waiting_enable_.front();
		this->waiting_enable_.pop();
		this->enables_.at(index) = true;
	}
	
	while (!this->waiting_disable_.empty())
	{
		const auto index = this->waiting_disable_.front();
		this->waiting_disable_.pop();
		this->enables_.at(index) = false;
	}
}

bool switcher::is_enable(int detail_index)
{
	return this->enables_.at(detail_index);
}
