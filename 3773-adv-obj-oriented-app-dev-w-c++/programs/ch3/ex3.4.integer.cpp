// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex3.4.integer.cpp
// Implementation of operations for the integer wrapper class
#include "ex3.4.integer.h"

Integer::Integer(int i) : value_(i) {}

int Integer::get() const { return value_; }

Integer& Integer::set(int n) {
  value_ = n;
  return *this;
}

Integer& Integer::add(const Integer& i) {
  value_ += i.value_;
  return *this;
}
