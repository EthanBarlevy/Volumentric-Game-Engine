#pragma once
#include "Math/transform.h"
#include "Serialization/serializable.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class)

namespace vl
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual void Update() = 0;
	};
}