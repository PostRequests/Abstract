#pragma once
#include "Point.h"
#include "Point3d.h"

class Point2d : public Point
{
protected:

	float x;
	float y;
public:
	Point2d(float x, float y): x(x), y(y){}
	Point2d() :x(0), y(0){}
	Point& move(Point & p) override{
		Point2d* p2d = dynamic_cast<Point2d*>(&p);
		if (p2d){
			this->x += p2d->getX();  
			this->y += p2d->getY();
		}
		else {
			throw std::exception("Not 2d");
		}
		return *this;
	}

	Point& show() override {
		std::cout << "Point: " << x << ", " << y << "\n";
		return *this;
	}
	inline float getX() { return x; }
	inline float getY() { return y; }
};

