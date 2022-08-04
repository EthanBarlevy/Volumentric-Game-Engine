#include "color.h"

namespace vl
{
	std::istream& operator >> (std::istream& stream, Color& c)
	{
		std::string line;
		std::getline(stream, line);

		std::string str;
		// { #, #, #}
		str = line.substr(line.find("{") + 2, line.find(",") - (line.find("{") + 2));
		c.r = (uint8_t)(stof(str) * 255);

		str = line.substr(line.find(",") + 2, (line.find(",", line.find(",") + 1) + 2 - line.find(",") + 2));
		c.g = (uint8_t)(stof(str) * 255);

		str = line.substr(line.find(",", line.find(",") + 1) + 2, line.find("}", line.find(",", line.find(","))));
		c.b = (uint8_t)(stof(str) * 255);

		c.a = 255;

		return stream;
	}
}