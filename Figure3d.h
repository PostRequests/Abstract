#pragma once
#include "Figure.h"
#include "Point3d.h"
class Figure3d : public Figure
{
protected:
	std::vector<Point3d> points;
public:
	Figure& move(float x, float y, float z) override{
		Point3d m(x, y, z);
		for (Point3d& i : points)
			i.move(&m);
		return *this;
	}
	Figure& add(Point* p) override {
		Point3d* p3d = dynamic_cast<Point3d*>(p);
		if(p3d)
			points.push_back(*p3d);
		else {
			throw std::exception("Not 3d");
		}
		return *this;
	}
	Figure& zoom_in(float dx, float dy, float dz) override{
        // 1. Вычисляем центр масс фигуры
        float centerX = 0, centerY = 0, centerZ = 0;
        for (Point3d& point : points) {
            centerX += point.getX();
            centerY += point.getY();
            centerZ += point.getZ();
        }
        centerX /= points.size();
        centerY /= points.size();
        centerZ /= points.size();
        // 2. Коэффициенты масштабирования по осям
        const float scaleX = 1.0f + dx;
        const float scaleY = 1.0f + dy;
        const float scaleZ = 1.0f + dz;
        // 3. Применяем масштабирование относительно центра
        for (Point3d& p : points) {
            // Вычисляем смещение от центра
            float offsetX = p.getX() - centerX;
            float offsetY = p.getY() - centerY;
            float offsetZ = p.getZ() - centerZ;
            Point* mov = new Point3d (
                centerX + offsetX * scaleX - p.getX(),
                centerY + offsetY * scaleY - p.getY(),
                centerZ + offsetZ * scaleZ - p.getZ());
            // Масштабируем и перемещаем точку
            p.move(mov);
            delete mov;
        }
        return *this;
	}

	Figure& show() override {
		std::cout << "Figure :\n";
		for (Point3d& i : points)
			i.show();
		return *this;
	}
    Figure3d* clone() override { return new Figure3d(*this); }
};

