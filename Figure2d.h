#pragma once
#include "Figure.h"
#include "Point2d.h"
class Figure2d : public Figure
{
protected:
	std::vector<Point> points;
public:
	Figure& move(float x, float y, float z = 0) override{
		for (Point& i : points)
			i.move(x, y, 0);
	}
	Figure& zoom_in() override{
		return *this;
	}
	Figure& add(Point& a) override{
		points.push_back(a);
	}
	Figure& show() override{
		std::cout << "Figure :\n";
		for (Point& i : points)
			i.show();
		return *this;
	}
};

