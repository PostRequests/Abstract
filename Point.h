#pragma once
#include <iostream>
class Point
{
protected:
	float x;
	float y;
	float z;
public:
	Point(float x, float y, float z = 0) : x(x), y(y), z(z){}

	virtual Point& move(float x, float y, float z) = 0;
	virtual Point& show() = 0;

	inline float getX() { return x; }
	inline float getY() { return y; }
	inline float getZ() { return z; }
};

