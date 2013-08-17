/**
 * COMP 3773 - Assignment 6 - Exercise 8.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation (definitions) of the basic Point class.
 * A simple 3-dimensional point with some useful operations.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date August 2013
 * @version 1.0
 */

#include <cmath>

#include "8.9-point.h"

Point::Point(double x, double y, double z) : x_(x), y_(y), z_(z) {}


bool Point::isEqual(const Point &other) const
{
  return distanceSquared(other) < sq(EPSILON);
}

// Distance is sqrt(dx*dx + dy*dy + dz*dz).
double Point::distance(const Point &other) const
{
  return sqrt(sq(x_ - other.x_) + sq(y_ - other.y_) + sq(z_ - other.z_));
}

double Point::distanceSquared(const Point &other) const
{
  return sq(x_ - other.x_) + sq(y_ - other.y_) + sq(z_ - other.z_);
}

// Friends

ostream &operator<<(ostream &out, const Point &p)
{
  return out << "(" << p.x_ << ", " << p.y_ << ", " << p.z_ << ")";
}

// Helpers

bool operator==(const Point &a, const Point &b)
{
  return fabs(a.x() - b.x()) < EPSILON &&
         fabs(a.y() - b.y()) < EPSILON &&
         fabs(a.z() - b.z()) < EPSILON;
}

bool operator!=(const Point &a, const Point &b)
{
  return !(a == b);
}
