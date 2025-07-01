#pragma once
#include "Point3d.h"
#include "Figure.h"
#include "Figure3d.h"
#include "Figure2d.h"
class AbstractFigure
{
public:
	
	virtual Figure* create() = 0;
	virtual ~AbstractFigure() = default;
};

class Figure2 : public AbstractFigure {
public:
	Figure* create() override {
		return new Figure2d();
	}
};

class Figure3 : public AbstractFigure {
public:
	Figure* create() override {
		return new Figure3d();
	}
};

