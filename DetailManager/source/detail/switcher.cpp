#include "switcher.h"

#include <string>

#include "connect/logger.h"

switcher::switcher() : enables_(100, false) {}

void switcher::enable(int detail_index)
{
	this->enables_.at(detail_index) = true;
	logger::get_logger().write_debug("enable(" + std::to_string(detail_index) + ") : enabled.");
}
void switcher::disable(int detail_index)
{
	this->enables_.at(detail_index) = false;
	logger::get_logger().write_debug("disable(" + std::to_string(detail_index) + ") : disabled.");
}

void switcher::enable_when_rise(int detail_index)
{
	this->waiting_enable_.push(detail_index);
	logger::get_logger().write_debug("enable_when_rise(" + std::to_string(detail_index) + ") : pushed.");
}

void switcher::disable_when_rise(int detail_index)
{
	this->waiting_disable_.push(detail_index);
	logger::get_logger().write_debug("disable_when_rise(" + std::to_string(detail_index) + ") : pushed.");
}

void switcher::rise()
{
	logger::get_logger().write_debug("rise!");
	
	while(!this->waiting_enable_.empty())
	{
		const auto index = this->waiting_enable_.front();
		this->waiting_enable_.pop();
		this->enables_.at(index) = true;
		logger::get_logger().write_debug("enabled " + std::to_string(index));
	}

	// 有効と無効が被ったら無効を優先
	while (!this->waiting_disable_.empty())
	{
		const auto index = this->waiting_disable_.front();
		this->waiting_disable_.pop();
		this->enables_.at(index) = false;
		logger::get_logger().write_debug("disabled " + std::to_string(index));
	}
}

bool switcher::is_enable(int detail_index)
{
	return this->enables_.at(detail_index);
}
