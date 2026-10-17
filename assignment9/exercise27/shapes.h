// inheritance: abstract classes and pure virtual functions
// author:  Holger Arndt / Frederick Lancia
// version: 19.12.2025

#ifndef SHAPES_H
#define SHAPES_H

class Shape;

#include "pv2d.h"
#include "shapewin.h"
#include <math.h>


class Shape
{
protected:
  Point2D ref;
  virtual void drawMe(ShapeWindow& swin) const = 0;
public:
  Shape(const Point2D& r) : ref{r} {}
  virtual ~Shape() = default;
  void moveto(const Point2D& p) { ref = p; }
  void shift(const Vector2D& v) { ref += v; }
  virtual double area() const = 0;
  friend class ShapeWindow;
};

class Dot : public Shape
{
protected:
  virtual void drawMe(ShapeWindow& swin) const override;
public:
  Dot(const Point2D& p) : Shape{p} {}
  Dot(double x, double y) : Shape{Point2D{x, y}} {}
  virtual double area() const override { return 0.0; }
};

class Line : public Shape
{
protected:
  Vector2D end;
  virtual void drawMe(ShapeWindow& swin) const override;
public:
  Line(const Point2D& a, const Point2D& b) : Shape{a}, end{b - a} {}
  virtual double area() const override { return 0.0; }
};

class Rectangle : public Shape
{
protected:
  Vector2D lr;  // vector from the ref point to the lower right corner
  virtual void drawMe(ShapeWindow& swin) const override;
public:
  Rectangle(const Point2D& ul, double w, double h) : Shape{ul}, lr{w, h} {}
  virtual double area() const override { return lr.x * lr.y; }
};

class Square : public Rectangle
{
public:
  Square(const Point2D& ul, double w) : Rectangle{ul, w, w} {}
};

class Polygon : public Shape
{
protected:
  int numc;
  Vector2D* corners;  // vectors from the ref point to ALL corners
  virtual void drawMe(ShapeWindow& swin) const override;
public:
  Polygon(const Point2D& r, int n, const Point2D c[]);
  virtual ~Polygon() { delete[] corners; }
  virtual double area() const override;
};

class RoundedRectangle : public Rectangle
{
protected:
  double radius;
  virtual void drawMe(ShapeWindow& swin) const override;
public:
  RoundedRectangle(const Point2D& ul, double w, double h, double r) : Rectangle{ul, w, h}, radius(r) {}
  virtual double area() const override { return lr.x * lr.y - 4 * radius * radius + M_PI * radius * radius; }
}

#endif
