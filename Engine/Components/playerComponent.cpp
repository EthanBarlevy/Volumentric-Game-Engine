#include "playerComponent.h"
#include "audioComponent.h"
#include "physicsComponent.h"
#include "Input/inputSystem.h"
#include "Core/time.h"
#include "Math/mathUtils.h"
#include "Framework/actor.h"

namespace vl
{
	// i refuse to include engine.h i think that its weird because its almost recursive
	extern InputSystem g_inputSystem;
	extern Time g_time;

	void PlayerComponent::Update()
	{
		// this all kinda should have physics so just imagine that there is physics until its added
		Vector2 direction = Vector2::ZERO;
		if (vl::g_inputSystem.GetKeyDown(vl::key_left))
		{
			m_owner->GetTransform().rotation -= 180 * (float)g_time.deltaTime;
		}

		if (vl::g_inputSystem.GetKeyDown(vl::key_right))
		{
			m_owner->GetTransform().rotation += 180 * (float)g_time.deltaTime;
		}

		float thrust = 0;
		if (vl::g_inputSystem.GetKeyDown(vl::key_up))
		{
			thrust = 10000;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			// thrust
			Vector2 force = Vector2::Rotate(Vector2::RIGHT, math::DegToRad(m_owner->GetTransform().rotation)) * thrust;
			component->ApplyForce(force);

			// gravity
			force = (Vector2{ 250, 250 } - m_owner->GetTransform().position).Normalized() * 1000.0f;
			component->ApplyForce(force);
		}

		m_owner->GetTransform().position += direction * 300 * (float)g_time.deltaTime;

		if (vl::g_inputSystem.GetKeyState(vl::key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component)
			{
				component->Play();
			}
		}
	}
}


