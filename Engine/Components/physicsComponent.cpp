#include "physicsComponent.h"
#include "Core/time.h"
#include "Framework/actor.h"

namespace vl
{
	extern Time g_time;

	void PhysicsComponent::Update()
	{
		m_velocity += m_acceleration * (float)g_time.deltaTime;
		m_owner->GetTransform().position += m_velocity * (float)g_time.deltaTime;
		m_velocity *= m_damping;

		m_acceleration = Vector2::ZERO;
	}
}
