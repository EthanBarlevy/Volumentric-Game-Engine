#include "physicsComponent.h"
#include "Framework/actor.h"
#include "includes.h"

namespace vl
{
	bool PhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}
	bool PhysicsComponent::Read(const rapidjson::Value& value)
	{
		return false;
	}

	void PhysicsComponent::Update()
	{
		m_velocity += m_acceleration * (float)g_time.deltaTime;
		m_velocity *= m_damping;
		m_owner->GetTransform().position += m_velocity * (float)g_time.deltaTime;

		m_acceleration = Vector2::ZERO;
	}
}
