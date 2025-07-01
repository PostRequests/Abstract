#pragma once
#include "Figure.h"
#include "Point3d.h"
class Figure3d : public Figure
{
protected:
	std::vector<Point3d> points;
public:
	Figure& move(float x, float y, float z) override{
		for (Point3d& i : points)
			i.move(x, y, z);
		return *this;
	}
	Figure& add(Point& p) override {
		Point3d* p3d = dynamic_cast<Point3d*>(&p);
		points.push_back(*p3d);
		return *this;
	}
	Figure& zoom_in() override{
		return *this;
	}

	Figure& show() override {
		std::cout << "Figure :\n";
		for (Point3d& i : points)
			i.show();
		return *this;
	}
};

