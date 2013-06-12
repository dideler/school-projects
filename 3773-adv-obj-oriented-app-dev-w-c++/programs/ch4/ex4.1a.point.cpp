// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File ex4.1a.point.cpp
// Implementation of a modified point class

#include "ex4.1a.point.h"
#include <cmath>

// Note that kind is initialized first, this is because
// it was declared first in the header. Error otherwise.
Point::Point(double x, double y, System k): kind(k), x_(x), y_(y) { }

Point Point::cartesian(double x, double y) {
  return Point(x, y, CARTESIAN); 
}

Point Point::polar(double radius, double angle) {
  return Point(radius*cos(angle), radius*sin(angle), POLAR); 
}

double Point::x() const { return x_; }
double Point::y() const { return y_; }
