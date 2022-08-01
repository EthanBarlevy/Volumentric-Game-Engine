#pragma once
#include "renderer.h"
#include "../Math/transform.h"
#include <vector>

namespace vl 
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<vl::Vector2>& points, const vl::Color& color) : m_points{ points }, m_color{ color } {}
		~Model() = default;

		Model(const std::string& filename);

		void Draw(Renderer& renderer, const Vector2& position, float angle, float scale = 1);
		void Draw(Renderer& renderer, const Transform& transform);

		void Load(const std::string& filename);
		float CalcRadius();

		float GetRadius() { return m_radius; }

		Color& GetColor() { return m_color; }

	private:
		Color m_color{0, 0, 0, 0};
		std::vector<vl::Vector2> m_points;

		float m_radius = 0;
	};
}