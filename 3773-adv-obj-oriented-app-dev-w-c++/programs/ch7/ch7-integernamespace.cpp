// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Section 7.3, page 282
//
// Implementation of a namespace with a class showing overloaded operators.

#include "ch7-integernamespace.h"

namespace IntegerNamespace
{

// Class members
Integer::Integer(int i) : value_(i) {}

int Integer::get() const { return value_; }

Integer& Integer::operator+=(const Integer& i)
{
  value_ += i.value_;
  return *this;
}

Integer& Integer::operator+=(int v)
{
  value_ += v;
  return *this;
}

Integer& Integer::operator++() // Note that it does pre-increment.
{
  ++value_;
  return *this;
}

// Helpers
Integer operator+(int v, const Integer& i)
{
  Integer j = i;
  j += v;  // call: Integer::operator+=(int)
  return j;
}

Integer operator+(const Integer& i, int v)
{
  Integer j = i;
  j += v;  // call: Integer::operator+=(int)
  return j;
}

Integer operator+(const Integer& i1, const Integer& i2)
{
  Integer j = i1;
  j += i2;  // call: Integer::operator+=(const Integer&)
  return j;
}

// FIXME: empty int parameter?
Integer operator++(Integer& x, int) // postfix
{
  Integer local(x); // save x
  ++x; // update x using member
  return local;
}

istream& operator>>(istream& is, Integer& i)
{
  is >> i.value_; // friends are allowed
  return is;
}

ostream& operator<<(ostream& os, const Integer& i)
{
  os << i.get();
  return os;
}

} // namespace IntegerNamespace
