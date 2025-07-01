#pragma once
#include "Figure.h"
#include "Point2d.h"
#include "Point3d.h"
#include "Point.h"
class Figure2d : public Figure
{
protected:
	std::vector<Point2d> points;
public:
    Figure2d(){}
	Figure& move(float x, float y, float z = 0) override{
		Point2d m(x, y);
		for (Point2d& i : points)
			i.move(&m);
		return *this;
	}
	Figure& zoom_in(float dx, float dy, float dz) override{
        // 1. Вычисляем центр масс фигуры
        float centerX = 0, centerY = 0;
        for (Point2d& p : points) {
            centerX += p.getX();
            centerY += p.getY();
        }
        centerX /= points.size();
        centerY /= points.size();
        // 2. Коэффициенты масштабирования по осям
        const float scaleX = 1.0f + dx;
        const float scaleY = 1.0f + dy;
        const float scaleZ = 1.0f + dz;
        // 3. Применяем масштабирование относительно центра
        for (Point2d& p : points) {
            // Вычисляем смещение от центра
            float offsetX = p.getX() - centerX;
            float offsetY = p.getY() - centerY;
            Point* mov = new Point2d(
                centerX + offsetX * scaleX - p.getX(),
                centerY + offsetY * scaleY - p.getY());
            // Масштабируем и перемещаем точку
            p.move(mov);
            delete mov;
        }
        return *this;
	}
	Figure& add(Point* a) override{
		Point2d* p2d = dynamic_cast<Point2d*>(a);
		if(p2d)
			points.push_back(*p2d);
		else {
			throw std::exception("Not 2d");
		}
		return *this;
	}
	Figure& show() override{
		std::cout << "Figure :\n";
		for (Point& i : points)
			i.show();
		return *this;
	}

    Figure2d* clone() override { return new Figure2d(*this); }
};

