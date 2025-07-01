#pragma once
#include "Point.h"
#include "Point2d.h"
class Point3d : public Point
{
protected:
	float x;
	float y;
	float z;
public:
	Point3d(float x, float y, float z) : x(x), y(y), z(z) {}
	Point3d() :x(0), y(0), z(0) {}
	Point& move(Point* p) override {
		Point3d* p3d = dynamic_cast<Point3d*>(p);
		if (p3d) {
			this->x += p3d->getX();
			this->y += p3d->getY();
			this->z += p3d->getZ();
		}
		else {
			throw std::exception("Not 3d");
		}
		return *this;
	}

	Point& show()  override{
		std::cout << "Point3d: " << x << ", " << y << ", " << z << "\n";
		return *this;
	}

	inline float getX() { return x; }
	inline float getY() { return y; }
	inline float getZ() { return z; }
	Point3d* clone() { return new Point3d(*this); }
};

