#include "spriteComponent.h"
#include "Framework/actor.h"

namespace vl
{
	bool SpriteComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}
	bool SpriteComponent::Read(const rapidjson::Value& value)
	{
		return false;
	}
	
	void SpriteComponent::Update()
	{
		//
	}

	void SpriteComponent::Draw(Renderer& renderer)
	{
		renderer.Draw(m_texture, m_owner->GetTransform());
	}
}
