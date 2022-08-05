#include "playerComponent.h"
#include "Input/inputSystem.h"
#include "Framework/actor.h"

namespace vl
{
	// i hate this but i really dont think that there is a way to do it without this
	extern InputSystem g_inputSystem;

	void PlayerComponent::Update()
	{
		// this all kinda should have physics so just imagine that there is physics until its added
		if (vl::g_inputSystem.GetKeyDown(vl::key_left))
		{
			m_owner->GetTransform().position.x -= 10;
		}

		if (vl::g_inputSystem.GetKeyDown(vl::key_right))
		{
			m_owner->GetTransform().position.x += 10;
		}

		if (vl::g_inputSystem.GetKeyDown(vl::key_up))
		{
			m_owner->GetTransform().position.y -= 10;
		}

		if (vl::g_inputSystem.GetKeyDown(vl::key_down))
		{
			m_owner->GetTransform().position.y += 10;
		}
	}
}


