// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex4.1.point.cpp
// Implementation of class point

#include "ex4.1.point.h"
#include <cmath>

Point::Point(double x, double y): x_(x), y_(y) { }

Point Point::cartesian(double x, double y) {
  return Point(x, y); 
}

Point Point::polar(double radius, double angle) {
  return Point(radius*cos(angle), radius*sin(angle)); 
}

double Point::x() const { return x_; }
double Point::y() const { return y_; }
