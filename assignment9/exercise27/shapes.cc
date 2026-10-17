// inheritance: Shape as a new base class, implementation
// author:  Holger Arndt
// version: 27.07.2017

#include <cmath>
#include "shapes.h"
#include "shapewin.h"

void Dot::drawMe(ShapeWindow& swin) const
{
  swin.dot(ref);
}

void Line::drawMe(ShapeWindow& swin) const
{
  swin.line(ref, ref + end);
}

void Rectangle::drawMe(ShapeWindow& swin) const
{
  swin.rect(ref, ref + lr);
}

void Polygon::drawMe(ShapeWindow& swin) const
{
  for (int i{0}; i < numc - 1; ++i)
    swin.line(ref + corners[i], ref + corners[i + 1]);
  swin.line(ref + corners[numc - 1], ref + corners[0]);
}

Polygon::Polygon(const Point2D& r, int n, const Point2D c[]) : Shape(r), numc(n)
{
  corners = new Vector2D[n];
  for (int i{0}; i < numc; ++i)
    corners[i] = c[i] - ref;
}

double Polygon::area() const
{
  double a{0};
  for (int i{0}; i < numc - 1; ++i)
    a += (corners[i].y + corners[i + 1].y) * (corners[i].x - corners[i + 1].x);
  a += (corners[numc - 1].y + corners[0].y)
    * (corners[numc - 1].x - corners[0].x);
  a = abs(a / 2);
  return a;
}
