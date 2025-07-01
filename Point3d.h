#pragma once
#include "Point.h"
#include "Point2d.h"
class Point3d : public Point
{
public:
	float x;
	float y;
	float z;
public:
	Point3d(float x, float y, float z) : x(x), y(y), z(z) {}
	Point3d() :x(0), y(0), z(0) {}
	//Point3d(const Point2d& p) : x(p.getX()), y(p.getY()), z(0) {}
	Point& move(float x, float y, float z) {
		Point::move(x, y, z);
		this->z += z;
		return *this;
	}

	Point& show()  override{
		std::cout << "Point3d: " << x << ", " << y << ", " << z << "\n";
		return *this;
	}

	inline float getX() { return x; }
	inline float getY() { return y; }
	inline float getZ() { return z; }
};

