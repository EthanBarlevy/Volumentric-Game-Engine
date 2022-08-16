#pragma once
#include <string>

namespace vl
{
	class Resource
	{
	public:
		virtual bool Create(const std::string& name, ...) = 0;

	};
}