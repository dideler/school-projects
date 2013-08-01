/**
 * COMP 3773 - Assignment 5 - Exercise 7.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation (definitions) of the basic Segment class.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#include "7.11-point.h"
#include "7.11-segment.h"

Segment::Segment(const Point &p1, const Point &p2)
    : p1_(new Point(p1)),
      p2_(new Point(p2)) {}

Segment::Segment(const Segment &other)
    : p1_(new Point(*other.p1_)),
      p2_(new Point(*other.p2_)) {}

Segment::~Segment()
{
  delete p1_;
  delete p2_;
}

ostream &operator<<(ostream &out, const Segment &s)
{
  return out << *s.p1_ << "-" << *s.p2_;
}
