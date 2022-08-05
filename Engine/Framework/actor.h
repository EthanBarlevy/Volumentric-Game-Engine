#pragma once
#include "gameObject.h"
#include "component.h"
#include <vector>
#include <memory>

namespace vl
{
	class Scene;
	class Renderer;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {}

		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		void AddComponent(std::unique_ptr<Component> component);

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; }// m_model.GetRadius()* (float)std::max(m_transform.scale.x, m_transform.scale.y); }

		std::string& GetTag() { return m_tag; }
		Transform GetTransform() { return m_transform; }

		friend class Scene;

	protected:
		Scene* m_scene{ nullptr };
		Transform m_transform;
		std::vector<std::unique_ptr<Component>> m_components;

		std::string m_tag;
		bool m_destroy{ false };

		// physics
		Vector2 m_velocity;
		float m_damping = 1;
	};
}