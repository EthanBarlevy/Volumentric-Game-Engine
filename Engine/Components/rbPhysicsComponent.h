#pragma once
#include "physicsComponent.h"

namespace vl
{
	class RBPhysicsCompnent : public PhysicsComponent
	{
	public:
		RBPhysicsCompnent() = default;
		~RBPhysicsCompnent();

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Initialize() override;
		void Update() override;
		virtual void ApplyForce(const Vector2& force);

	private:
		PhysicsSystem::RigidBodyData data;
		b2Body* m_body{ nullptr };
	};
}