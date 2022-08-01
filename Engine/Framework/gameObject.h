#pragma once
#include "../Math/transform.h"

namespace vl
{
	class GameObject
	{
	public:
		GameObject() = default;
		GameObject(const Transform& transform) : m_transform{ transform } {}

		virtual void Update() = 0;


		Transform& GetTransform() { return m_transform; }

		Transform m_transform;
	protected:

	};
}