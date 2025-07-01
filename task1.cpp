// "Абстрактная фабрика"
#include "AbstractFigure.h"
#include "protoGeomObj.h"
#include "Lib/Menu/Menu.h"
#include <iostream>

int main()
{
  
    Menu menu;
    menu.addItem("2d Фабрика", []() {
        Box::drawFillBox(2, 10, 20, 15);
        AbstractFigure* f = new Figure2(); //Фигура 2д
        Figure* myFigure = f->create();
        for (size_t i = 0; i < 4; i++)
        {
            Point* pp = new Point2d(rand() % 20, rand() % 20);
            myFigure->add(pp);
            delete pp;
        }
        Position showPoint(1, 10);
        showPoint.go();
        myFigure->show();
        delete f;
        delete myFigure;
    });
    menu.addItem("3d Фабрика", []() {
        Box::drawFillBox(2, 10, 20, 15);
        AbstractFigure* f = new Figure3(); //Фигура 2д
        Figure* myFigure = f->create();
        for (size_t i = 0; i < 4; i++)
        {
            Point* pp = new Point3d(rand() % 20, rand() % 20, rand() % 20);
            myFigure->add(pp);
            delete pp;
        }
        Position showPoint(1, 10);
        showPoint.go();
        myFigure->show();
        delete f;
        delete myFigure;
        });
    menu.run();
}