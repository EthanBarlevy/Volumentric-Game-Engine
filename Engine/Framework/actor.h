#pragma once
#include "gameObject.h"
#include "../Renderer/model.h"


namespace vl
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : GameObject{ transform }, m_model{ model }, m_scene{ nullptr }{}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return m_model.GetRadius() * m_transform.scale; }

		std::string& GetTag() { return m_tag; }

		friend class Scene;

	protected:
		Model m_model;
		Scene* m_scene;

		std::string m_tag;
		bool m_destroy{ false };
		// physics
		Vector2 m_velocity;
		float m_damping = 1;
	};
}