#pragma once
#include <iostream>
#include "protoGeomObj.h"
class Point : public protoGeomObj
{
public:
	virtual Point& move(Point*) = 0;
	virtual Point& show() = 0;
	virtual Point* clone() = 0;
	virtual ~Point() = default;
	void info() override {
		std::cout << "Point\n";
	}
};

