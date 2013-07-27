/**
 * COMP 3773 - Assignment 5 - Exercise 7.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation (definition) of Point class.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#include "7.11-point.h"

Point::Point(int x, int y, int z) : x_(x), y_(y), z_(z) {}

ostream &operator<<(ostream &out, const Point &p)
{
  return out << "(" << p.x_ << ", " << p.y_ << ", " << p.z_ << ")";
}
