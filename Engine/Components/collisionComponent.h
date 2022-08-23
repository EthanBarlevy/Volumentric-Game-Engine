#pragma once
#include "Framework/component.h"
#include "Physics/collision.h"
#include "Physics/physicsSystem.h"

namespace vl
{
	class CollisionComponent : public Component, public ICollidable
	{
	public:
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

	private:
		PhysicsSystem::CollisionData data;
	};
}