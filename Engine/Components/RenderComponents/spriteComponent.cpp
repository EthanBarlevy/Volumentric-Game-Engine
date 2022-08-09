#include "spriteComponent.h"
#include "Framework/actor.h"

namespace vl
{
	void SpriteComponent::Update()
	{

	}

	void SpriteComponent::Draw(Renderer& renderer)
	{
		renderer.Draw(m_texture, m_owner->GetTransform());
	}
}
