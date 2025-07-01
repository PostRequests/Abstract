#pragma once
#include "protoGeomObj.h"
#include "Point.h"
#include <vector>
class Figure :  public protoGeomObj
{
protected:
public:
	virtual Figure* clone() = 0;
	virtual Figure& move(float x, float y, float z) = 0;
	virtual Figure& zoom_in(float x, float y, float z) = 0;
	virtual Figure& add(Point* a) = 0;
	virtual Figure& show() = 0;
	void info() override {
		std::cout << "Point\n";
	}
	virtual ~Figure() override = default;
};

