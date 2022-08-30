#include "playerComponent.h"
#include "audioComponent.h"
#include "physicsComponent.h"
#include "collisionComponent.h"
#include "RenderComponents/renderComponent.h"
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
		CharacterComponent::Read(value);
		READ_DATA(value, jump);

		return true;
	}

	void PlayerComponent::Initialize()
	{
		CharacterComponent::Initialize();
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

		Vector2 velocity;
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
			velocity = component->velocity;
		}

		// jump
		if (vl::g_inputSystem.GetKeyState(vl::key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::UP * 1000);
			}
		}

		if (vl::g_inputSystem.GetKeyDown(vl::key_up))
		{
			// currently unused
		}

		auto renderComponent = m_owner->GetComponent<RenderComponent>();
		if (renderComponent)
		{
			if (velocity.x != 0) renderComponent->SetFlipHorizontal(velocity.x < 0);
		}
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			Event event;
			event.name = "EVENT_ADD_POINTS";
			event.data = 100;

			g_eventManager.Notify(event);
			other->Destroy();
		}

		if (other->GetTag() == "Enemy")
		{
			Event event;
			event.name = "EVENT_DAMAGE";
			event.data = damage;
			event.reciever = other;

			g_eventManager.Notify(event);
		}
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		//
	}

	void PlayerComponent::OnNotify(const Event& event)
	{
		if (event.name == "EVENT_DAMAGE")
		{
			health -= std::get<float>(event.data);
			std::cout << health << std::endl;
			if (health <= 0)
			{
				Event event;
				event.name = "EVENT_PLAYER_DEAD";

				g_eventManager.Notify(event);
			}
		}
	}
}


