#pragma once
#include "Math/transform.h"

namespace vl
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual void Update() = 0;
	};
}