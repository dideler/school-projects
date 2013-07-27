/**
 * COMP 3773 - Assignment 5 - Exercise 7.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#include "7.11-point.h"
#include "7.11-segment.h"

#include <iostream>
using namespace std;

Segment::Segment(const Point &p1, const Point &p2)
    : p1_(new Point(p1)),
      p2_(new Point(p2)) {}

Segment::~Segment()
{
  if (p1_ != nullptr) delete p1_;
  if (p2_ != nullptr) delete p2_;
}

ostream &operator<<(ostream &out, const Segment &s)
{
  return out << *s.p1_ << "-" << *s.p2_;
}
