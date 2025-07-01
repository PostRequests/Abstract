#pragma once
#include "Figure.h"
#include "Point2d.h"
#include "Point3d.h"
class Figure2d : public Figure
{
protected:
	std::vector<Point2d> points;
public:
	Figure& move(float x, float y, float z = 0) override{
		for (Point2d& i : points)
			i.move(x, y);
		return *this;
	}
	Figure& zoom_in() override{
		return *this;
	}
	Figure& add(Point& a) override{
		Point2d* p2d = dynamic_cast<Point2d*>(&a);
		if(p2d)
			points.push_back(*p2d);
		return *this;
	}
	Figure& show() override{
		std::cout << "Figure :\n";
		for (Point& i : points)
			i.show();
		return *this;
	}
};

