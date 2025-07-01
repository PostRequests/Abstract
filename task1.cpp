// "Абстрактная фабрика"
#include "AbstractFigure.h"

#include <iostream>

int main()
{
    AbstractFigure* f = new Figure2(); //Фигура 2д
    Figure* myFigure = f->create();
    Point* a = new Point2d();
    myFigure->add(*a).show();

    AbstractFigure* d = new Figure3(); //Фигура 3д
    Figure* myFigure2 = d->create();
    Point* b = new Point3d();
    myFigure2->add(*b).show();
}