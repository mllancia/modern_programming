// classes for points and vectors in 2D
// author:  Holger Arndt
// version: 21.11.2023

#ifndef PV2D_H
#define PV2D_H

#include <cmath>
#include <iostream>

class Vector2D;

class Point2D
{
public:
  double x;
  double y;
  constexpr Point2D() : x{0}, y{0} {}
  constexpr Point2D(double xx, double yy) : x{xx}, y{yy} {}
  constexpr Point2D& operator+=(const Vector2D& v);
};

class Vector2D
{
public:
  double x;
  double y;
  constexpr Vector2D() : x{0}, y{0} {}
  constexpr Vector2D(double xx, double yy) : x{xx}, y{yy} {}
};

inline constexpr Point2D& Point2D::operator+=(const Vector2D& v)
{
  x += v.x;
  y += v.y;
  return *this;
}

inline constexpr Point2D operator+(const Point2D& p, const Vector2D& v)
{
  return Point2D{p.x + v.x, p.y + v.y};
}

inline constexpr Vector2D operator-(const Point2D& p, const Point2D& v)
{
  return Vector2D{p.x - v.x, p.y - v.y};
}

inline std::ostream& operator<<(std::ostream& os, const Point2D& p)
{
  return os << '(' << p.x << ',' << p.y << ')';
}

#endif
