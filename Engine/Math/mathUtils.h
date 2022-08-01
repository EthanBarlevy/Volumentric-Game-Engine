#pragma once
//#ifndef __MATH_UTILS_H__
//#define __MATH_UTILS_H__

namespace math 
{
	const float PI = 3.14159265359f; // 180
	const float TWOPI = 6.28318530718f; // 360
	const float HALFPI = 1.57079632679f; // 90

	inline float DegToRad(float degrees) { return degrees * (PI / 180); }
	inline float RadToDeg(float radians) { return radians * (180 / PI); }

	int sqr(int i);
	// inline is a workaround for defining functions in a header
	inline int half(int i) { return i / 2; } // it doenst actualy call it, it repaces the call with the definition
	
	inline float map(float value, float oldMin, float oldMax, float newMin, float newMax)
	{
		return ((value - oldMin) * (newMax - newMin)) / (oldMax - oldMin) + newMin;
	}

}
//#endif // __MATH_UTILS_H__