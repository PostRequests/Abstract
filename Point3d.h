#pragma once
#include "Point.h"
class Point3d : public Point
{
public:
	float z;
public:

	Point& move(float x, float y, float z) {
		Point::move(x, y, z);
		this->z += z;
		return *this;
	}

	Point& show()  override{
		std::cout << "Point3d: " << x << ", " << y << ", " << z << "\n";
		return *this;
	}

};

