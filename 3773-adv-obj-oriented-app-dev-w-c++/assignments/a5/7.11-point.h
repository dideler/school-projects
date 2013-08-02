/**
 * COMP 3773 - Assignment 5 - Exercise 7.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface (declarations) of the basic Point class.
 * A simple 3-dimensional point.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#ifndef POINT_H_
#define POINT_H_

#include <ostream>
using std::ostream;

class Point
{
 public:
  Point(int x = 0, int y = 0, int z = 0);

 private:
  int x_, y_, z_;

  // Overload the << operator to print a point.
  friend ostream &operator<<(ostream &out, const Point &p);
};

#endif
