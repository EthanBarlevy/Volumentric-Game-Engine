#pragma once
#include "vector2.h"
#include "matrix3x3.h"
#include "mathUtils.h"

namespace vl 
{
	struct Transform
	{
		Vector2 position;
		float rotation{ 0 };
		Vector2 scale{ 1, 1 };

		operator Matrix3x3 () const
		{
			Matrix3x3 mxS = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxR = Matrix3x3::CreateRotation(math::DegToRad(rotation));
			Matrix3x3 mxT = Matrix3x3::CreateTranslation(position);

			return { mxS * mxR * mxT };
		}
	};
}