// implementation of ShapeWindow
// author:  Holger Arndt
// version: 17.12.2019

#include <QPainter>
#include "pv2d.h"
#include "shapewin.h"
#include "shapes.h"

ShapeWindow::ShapeWindow(int n, Shape** sc) : num{n}, scene{new Shape*[num]}
{
  for (int i{0}; i < num; ++i)
    scene[i] = sc[i];
}

void ShapeWindow::drawShapes()
{
  for (int i{0}; i < num; ++i)
    scene[i]->drawMe(*this);
}

void ShapeWindow::dot(const Point2D& p)
{
  QPainter pnt{this};
  pnt.drawPoint(static_cast<int>(p.x), static_cast<int>(p.y));
}

void ShapeWindow::line(const Point2D& a, const Point2D& b)
{
  QPainter pnt{this};
  pnt.drawLine(static_cast<int>(a.x), static_cast<int>(a.y),
               static_cast<int>(b.x), static_cast<int>(b.y));
}

void ShapeWindow::rect(const Point2D& ul, const Point2D& lr)
{
  QPainter pnt{this};
  pnt.drawRect(static_cast<int>(ul.x), static_cast<int>(ul.y),
               static_cast<int>(lr.x - ul.x), static_cast<int>(lr.y - ul.y));
}
