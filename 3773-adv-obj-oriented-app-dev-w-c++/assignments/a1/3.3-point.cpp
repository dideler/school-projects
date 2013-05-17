/**
 * COMP 3773 - Assignment 1 - Exercise 3.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#include <cmath>
#include "3.3-point.h"

Point::Point(double x, double y) : x_(x), y_(y) {}

// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
double Point::distance(const Point &other) const
{
  return hypot(x_ - other.x_, y_ - other.y_);
}

ostream &operator<<(ostream &out, const Point &p)
{
  return out << "(" << p.x_ << ", " << p.y_ << ")";
}
