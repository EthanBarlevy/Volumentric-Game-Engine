#include "actor.h"
#include "../Math/mathUtils.h"

namespace vl
{
	void Actor::Draw(Renderer& renderer)
	{
		m_model.Draw(renderer, m_transform);
	}
}