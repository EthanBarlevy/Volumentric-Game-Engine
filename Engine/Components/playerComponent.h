#pragma once
#include "includes.h"
#include "Physics/collision.h"

namespace vl
{
	class PlayerComponent : public Component, public ICollidable
	{
	public:
		PlayerComponent() = default;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
		
		void Initialize() override;
		void Update() override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

	public:
		float speed{ 0 };

	};
}