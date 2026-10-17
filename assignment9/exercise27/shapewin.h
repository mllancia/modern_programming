// inheritance: window for shape-drawings, based on qt
// author:  Holger Arndt
// version: 21.01.2025

#ifndef SHAPEWIN_H
#define SHAPEWIN_H

class ShapeWindow;

#include <QPaintEvent>
#include <QWidget>
#include "pv2d.h"
#include "shapes.h"

class ShapeWindow : public QWidget
{
private:
  int num;          // number of graphical objects in the scene
  Shape** scene;
public:
  ShapeWindow(int n, Shape** sc);
  ~ShapeWindow() { delete[] scene; }
  void paintEvent([[maybe_unused]] QPaintEvent* qpe) override { drawShapes(); }
  void drawShapes();
  void dot(const Point2D& p);
  void line(const Point2D& a, const Point2D& b);
  void rect(const Point2D& ul, const Point2D& lr);
};

#endif
