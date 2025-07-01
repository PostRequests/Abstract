#pragma once
#include "Point.h"
#include "Point3d.h"
class Point2d : public Point
{
	float x;
	float y;
public:
	Point2d(float x, float y): x(x), y(y){}
	Point2d() :x(0), y(0){}
	//Point2d(Point3d& p): x(p.getX()), y(p.getY()){}
	Point& move(float x, float y, float z = 0) override{
		this->x += x;
		this->y += y;
		return *this;
	}

	Point& show() override {
		std::cout << "Point: " << x << ", " << y << "\n";
		return *this;
	}
	inline float getX() { return x; }
	inline float getY() { return y; }
};

