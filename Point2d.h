#pragma once
#include "Point.h"
class Point2d : public Point
{
public:
	Point& move(float x, float y, float z = 0) override{
		this->x += x;
		this->y += y;
		return *this;
	}

	Point& show() override {
		std::cout << "Point: " << x << ", " << y << "\n";
		return *this;
	}
};

