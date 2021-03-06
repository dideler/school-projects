// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex4.3.integer.cpp
// Implementation of operations for the integer wrapper class
#include "e4.3-integer.h"

Integer::Integer(int i) : value_(i) {}

Integer Integer::make(int i) { return Integer(i); }

int Integer::get() const { return value_; }

Integer& Integer::set(int n)
{
  value_ = n;
  return *this;
}

Integer& Integer::plus(int i)
{
  value_ += i;
  return *this;
}

Integer& Integer::plus(const Integer& i)
{
  value_ += i.value_;
  return *this;
}

Integer& Integer::minus(int i)
{
  value_ -= i;
  return *this;
}

Integer& Integer::minus(const Integer& i)
{
  value_ -= i.value_;
  return *this;
}

Integer Integer::times(const Integer& i) const
{
  return Integer(value_*i.value_);
}

Integer Integer::times(int i) const
{
  return Integer(i*value_);
}

Integer Integer::divide(const Integer& i) const throw(std::domain_error)
{
  if (i.value_ == 0)
    throw(std::domain_error("can't divide by 0"));
  return Integer(value_ / i.value_); 
}

Integer Integer::divide(int i) const throw(std::domain_error)
{
  if (i == 0)
    throw(std::domain_error("can't divide by 0"));
  return Integer(value_ / i);
}

Integer Integer::clone() const { return Integer(value_); }
