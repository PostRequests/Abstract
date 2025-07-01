#pragma once
#include <iostream>
class Point
{
public:
	virtual Point& move(float x, float y, float z) = 0;
	virtual Point& show() = 0;
};

