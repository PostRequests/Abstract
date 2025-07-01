#pragma once
#include "Figure.h"
#include "Point3d.h"
class Figure3d : public Figure
{
protected:
	std::vector<Point> points;
public:
	Figure& move(float x, float y, float z) override{
		for (Point& i : points)
			i.move(x, y, z);
		return *this;
	}
	Figure& add(Point& p) override {
		points.push_back(p);
		return *this;
	}
	Figure& zoom_in() override{
		return *this;
	}

	Figure& show() override {
		std::cout << "Figure :\n";
		for (Point& i : points)
			i.show();
		return *this;
	}
};

