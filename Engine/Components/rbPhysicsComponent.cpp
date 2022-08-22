#include "rbPhysicsComponent.h"
#include "Framework/actor.h"
#include "includes.h"

namespace vl
{
	RBPhysicsCompnent::~RBPhysicsCompnent()
	{
		if (m_body) { g_physicsSystem.DestroyBody(m_body); }
	}

	bool RBPhysicsCompnent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool RBPhysicsCompnent::Read(const rapidjson::Value& value)
	{
		PhysicsComponent::Read(value);

		READ_DATA(value, data.gravity_scale);
		READ_DATA(value, data.constrain_angle);
		READ_DATA(value, data.is_dynamic);

		return true;
	}

	void RBPhysicsCompnent::Initialize()
	{
		m_body = g_physicsSystem.CreateBody(PhysicsSystem::ScreenToWorld(m_owner->GetTransform().position), m_owner->GetTransform().rotation, data);
		m_body->SetGravityScale(data.gravity_scale);
		m_body->SetLinearDamping(damping);
	}

	void RBPhysicsCompnent::Update()
	{
		Vector2 position = B2VEC2_TO_VECTOR2(m_body->GetPosition());
		m_owner->GetTransform().position = PhysicsSystem::WorldToScreen(position);
		m_owner->GetTransform().rotation = m_body->GetAngle();
	}

	void RBPhysicsCompnent::ApplyForce(const Vector2& force)
	{
		m_body->ApplyForceToCenter(VECTOR2_TO_B2VEC2(force), true);
	}
}

