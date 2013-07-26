// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Section 7.3, page 286

#include "ch7-integer.h"

Integer::Integer(int val, int low, int high) throw(range_error)
    : value_(val), low_(low), high_(high)
{
  rangeCheck();
}

Integer::operator int() const { return value_; }

void Integer::rangeCheck() throw(range_error)
{
  if (value_ < low_ || value_ > high_) throw range_error("beyond range");
}

Integer operator+(const Integer& i, const Integer& j) throw(range_error)
{
  if (i.low_ != j.low_ || i.high_ != j.high_)
    throw range_error("incompatible ranges");

  int value = i.value_ + j.value_;
  if (value < i.low_ || value > i.high_) throw range_error("beyond range");
  return Integer(value);
}
