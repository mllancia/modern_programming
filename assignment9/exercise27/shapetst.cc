// main program for shapes
// author:  Holger Arndt
// version: 27.09.2018

#include <iostream>
#include <QApplication>
#include <QPalette>
#include "pv2d.h"
#include "shapes.h"
#include "shapewin.h"

using namespace std;

int main(int argc, char** argv)
{
  QApplication qapp{argc, argv};

  // Shape* s = new Shape(Point2D(2, 2)); // error: Shape is abstract
  Dot* d{new Dot{100, 100}};
  Rectangle* r{new Rectangle{Point2D{50, 50}, 100, 150}};
  Square* s{new Square{Point2D{75, 75}, 50}};
  Line* l{new Line{Point2D{10,210}, Point2D{190, 210}}};
  Point2D parr[]{ Point2D{250, 200}, Point2D{300, 250}, Point2D{250, 300},
                                                          Point2D{200, 250} };
  Polygon* p{new Polygon{Point2D{0, 0}, 4, parr}};
  Shape* scene[]{ d, r, s, l, p };
  for (int i{0}; i < 5; ++i)
    cout << "area of object " << i << ": " << scene[i]->area() << endl;

  ShapeWindow swin{5, scene};
  swin.resize(301, 301);
  swin.setMinimumSize(301, 301);
  swin.setPalette(QPalette{"black", "white"});

  swin.show();

  int exitStatus{qapp.exec()};
  for (int i{0}; i < 5; ++i)
    delete scene[i];
  return exitStatus;
}
