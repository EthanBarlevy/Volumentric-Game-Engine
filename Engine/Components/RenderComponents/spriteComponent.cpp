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
		std::string texture_name;
		READ_DATA(value, texture_name);

		m_texture = g_resourceManager.Get<Texture>(texture_name);
		return true;
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
