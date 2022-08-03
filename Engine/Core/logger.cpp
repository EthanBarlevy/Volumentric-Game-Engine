#include "logger.h"
#include <cstdarg>
#include <iostream>

// dont worry about any of this i just want cute console errors
#define NC "\e[0m"
#define RD "\e[0;31m"

namespace vl
{
	Logger g_logger; 

	void Logger::Log(const char* format, ...) // yah i totally understand this
	{
		va_list args;
		va_start(args, format);

		char str[1024];
		vsprintf_s(str, 1024, format, args);

		std::cout << RD << str << NC << std::endl;

		va_end(args);

	}
}

