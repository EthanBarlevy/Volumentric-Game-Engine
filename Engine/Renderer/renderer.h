#pragma once
#include "../Math/vector2.h"
#include "../Math/color.h"

struct SDL_Renderer;
struct SDL_Window;

namespace vl
{
	class Renderer
	{
	public:
		// new weird way to make a default constuctor / destuctor
		Renderer() = default;
		~Renderer() = default;

		void Initialize();
		void Shutodwn();

		void CreateWindow(const char* name, int width, int height);

		void BeginFrame();
		void EndFrame();

		void setClearColor(const Color& color) { m_clearColor = color; }

		//lameo float version
		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawPoint(float x, float y);

		//cool vector version
		void DrawLine(const Vector2& v1, const Vector2& v2, const Color& color);
		void DrawPoint(const Vector2& v, const Color& color);

		int GetWidth() { return m_width; }
		int GetHeight() { return m_height; }

		friend class Text;

	private:
		int m_width = 0;
		int m_height = 0;

		Color m_clearColor {0, 0, 0, 255};
		SDL_Renderer* m_renderer{ nullptr };
		SDL_Window* m_window{ nullptr };
	};
}