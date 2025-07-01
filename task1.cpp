// "Абстрактная фабрика"
#include "AbstractFigure.h"
#include "protoGeomObj.h"
#include <iostream>

int main()
{
    AbstractFigure* f = new Figure2(); //Фигура 2д
    Figure* myFigure = f->create();
    Point* a = new Point2d();
    Point2d fg(1, 2);
    myFigure->add(a);
    myFigure->add(new Point2d());
    myFigure->add(&fg).show();

    AbstractFigure* d = new Figure3(); //Фигура 3д
    Figure* myFigure2 = d->create();
    Point* b = new Point3d(2,3,4);
    Point* c =  b->clone() ;
    myFigure2->add(b).add(c).show();
}