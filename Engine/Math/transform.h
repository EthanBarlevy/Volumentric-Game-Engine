#pragma once
#include "vector2.h"
#include "matrix2x2.h"
#include "mathUtils.h"

namespace vl 
{
	struct Transform
	{
		Vector2 position;
		float rotation{ 0 };
		Vector2 scale{ 1, 1 };

		operator Matrix2x2 () const
		{
			// translation will be added later when we make a matrix3x3 struct
			Matrix2x2 mxS = Matrix2x2::CreateScale(scale);
			Matrix2x2 mxR = Matrix2x2::CreateRotation(math::DegToRad(rotation));

			return { mxS * mxR };
		}
	};
}