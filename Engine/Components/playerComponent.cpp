#include "playerComponent.h"
#include "audioComponent.h"
#include "physicsComponent.h"
#include "Math/mathUtils.h"
#include "Framework/actor.h"

namespace vl
{
	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}
	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}

	void PlayerComponent::Update()
	{
		// movement
		Vector2 direction = Vector2::ZERO;
		if (vl::g_inputSystem.GetKeyDown(vl::key_left))
		{
			direction = Vector2::LEFT;
		}

		if (vl::g_inputSystem.GetKeyDown(vl::key_right))
		{
			direction = Vector2::RIGHT;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
		}

		// jump
		if (vl::g_inputSystem.GetKeyState(vl::key_space) == InputSystem::State::Pressed)
		{
			//auto component = m_owner->GetComponent<AudioComponent>();
			//if (component)
			//{
			//	component->Play();
			//}
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::UP * 300);
			}
		}

		if (vl::g_inputSystem.GetKeyDown(vl::key_up))
		{
			// currently unused
		}
	}
}


