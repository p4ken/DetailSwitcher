#include "switcher.h"

#include <string>

#include "connect/logger.h"

switcher::switcher() : enables_(100, false) {}

void switcher::enable(const int detail_index)
{
	this->enables_.at(detail_index) = true;
	logger::get_logger().write_debug("enable(" + std::to_string(detail_index) + ") : enabled.");
}
void switcher::disable(const int detail_index)
{
	this->enables_.at(detail_index) = false;
	logger::get_logger().write_debug("disable(" + std::to_string(detail_index) + ") : disabled.");
}

void switcher::enable_when_rise(const int detail_index)
{
	const waiting request(detail_index, true);
	this->waitings_.push(request);
	logger::get_logger().write_debug("enable_when_rise(" + std::to_string(detail_index) + ") : pushed.");
}

void switcher::disable_when_rise(const int detail_index)
{
	const waiting request(detail_index, false);
	this->waitings_.push(request);
	logger::get_logger().write_debug("disable_when_rise(" + std::to_string(detail_index) + ") : pushed.");
}

void switcher::rise()
{
	logger::get_logger().write_debug("rise!");

	while (!this->waitings_.empty())
	{
		const auto request = this->waitings_.front();
		this->waitings_.pop();
		this->enables_.at(request.detail_index) = request.enable;
		const std::string did_text = request.enable ? "enabled " : "disabled ";
		logger::get_logger().write_debug(did_text + std::to_string(request.detail_index));
	}
}

bool switcher::is_enable(int detail_index)
{
	return this->enables_.at(detail_index);
}
