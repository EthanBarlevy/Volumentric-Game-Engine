#pragma once
#include <string>

namespace vl
{
	class Resource
	{
	public:
		virtual bool Create(const std::string& name, void* data = nullptr) = 0;

	};
}