#pragma once
#include <iostream>
class Point
{
public:
	virtual Point& move(Point&) = 0;
	virtual Point& show() = 0;
};

