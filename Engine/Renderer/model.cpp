#include "model.h"
#include "../Core/file.h"
#include <sstream>
#include <iostream>

namespace vl 
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_radius = CalcRadius();
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, float scale)
	{
		for (int i = 0; i < m_points.size(); i++)
		{
			vl::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			vl::Vector2 p2 = Vector2::Rotate((m_points[(i + 1) % m_points.size()] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}
	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		for (int i = 0; i < m_points.size(); i++)
		{
			vl::Vector2 p1 = Vector2::Rotate((m_points[i] * transform.scale), transform.rotation) + transform.position;
			vl::Vector2 p2 = Vector2::Rotate((m_points[(i + 1) % m_points.size()] * transform.scale), transform.rotation) + transform.position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}
	void Model::Load(const std::string& filename)
	{
		std::string buffer;
		vl::ReadFile(filename, buffer);

		// color being implemented 
		std::istringstream stream(buffer);
		stream >> m_color;

		// read number of points 
		std::string line;
		std::getline(stream, line);

		// get num of points
		size_t numPoints = std::stoi(line);

		// read points
		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;

			m_points.push_back(point);
		}

		//std::cout << line << std::endl;
	}

	float Model::CalcRadius()
	{
		float rad = 0;

		// find the largest radius
		for (auto& point : m_points)
		{
			if (point.Length() > rad) rad = point.Length();
		}

		return rad;
	}
}