#pragma once
//#ifndef __MATH_UTILS_H__
//#define __MATH_UTILS_H__

namespace math 
{
	constexpr float PI = 3.14159265359f; // 180
	constexpr float TWOPI = 6.28318530718f; // 360
	constexpr float HALFPI = 1.57079632679f; // 90

	constexpr float DegToRad(float degrees) { return degrees * (PI / 180); }
	constexpr float RadToDeg(float radians) { return radians * (180 / PI); }

	int sqr(int i);
	// inline is a workaround for defining functions in a header
	constexpr int half(int i) { return i / 2; } // it doenst actualy call it, it repaces the call with the definition
	
	// i just want this
	constexpr float map(float value, float oldMin, float oldMax, float newMin, float newMax)
	{
		return ((value - oldMin) * (newMax - newMin)) / (oldMax - oldMin) + newMin;
	}

}
//#endif // __MATH_UTILS_H__