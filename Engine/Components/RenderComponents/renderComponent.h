#pragma once
#include "Components/includes.h"
#include "Math/rect.h"

namespace vl
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		virtual void Draw(Renderer& renderer) = 0;

		virtual Rect& GetSource() { return source; }

	protected:
		Rect source;
	};
}