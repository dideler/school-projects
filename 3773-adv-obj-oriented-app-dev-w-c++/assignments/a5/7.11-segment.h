/**
 * COMP 3773 - Assignment 5 - Exercise 7.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface (declarations) for the basic Segment class.
 * A simple line segment (i.e. finite length) made of two points.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <ostream>
using std::ostream;

class Point; // Forward declaration.

class Segment
{
 public:
  Segment(const Point &p1, const Point &p2);
  Segment(const Segment &other);
  ~Segment();

 private:
  Point *p1_, *p2_;

  // Overload the << operator to print a line segment.
  friend ostream &operator<<(ostream &out, const Segment &s);
};

#endif
