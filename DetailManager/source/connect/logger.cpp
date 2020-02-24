#include "logger.h"

#include <string>
#include <windows.h>

namespace
{
	const std::string file_name = "C:\\Users\\p4\\Documents\\BveTs\\Scenarios\\p4ken\\economy\\ats\\detail_selector_log.txt";
}

logger::logger() : log_file_(file_name)
{
	char* text = strerror(errno);
	wchar_t wtext[50];
	mbstowcs(wtext, text, strlen(text) + 1);
	// MessageBox(NULL, wtext, TEXT("debug"), MB_OK);

	this->write_debug("logger init.");
}

logger& logger::get_logger()
{
	static logger logger;
	return logger;
}

void logger::write_error(const std::string& text)
{
	log_file_ << "error: " << text << std::endl;
}

void logger::write_debug(const std::string& text)
{
	log_file_ << "debug: " << text << std::endl;
}
