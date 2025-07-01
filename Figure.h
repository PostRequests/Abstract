#pragma once
#include "Point.h"
#include <vector>
class Figure 
{
protected:
public:
	virtual Figure& move(float x, float y, float z) = 0;
	virtual Figure& zoom_in() = 0;

	virtual Figure& add(Point& a) = 0;
	virtual Figure& show() = 0;
};

