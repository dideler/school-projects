// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Section 7.3, page 286
//
// Interface for Integer class, a wrapper class.

#ifndef CH7_INTEGER_H
#define CH7_INTEGER_H

#include <stdexcept>
using std::range_error;

class Integer
{
 public:
  explicit Integer(int val = 0, int low = 0, int high = 100) throw(range_error);
  friend Integer operator+(const Integer&, const Integer&) throw(range_error);
  operator int() const; // type conversion operator - risky to use!
  // ...
 private:
  void rangeCheck() throw(range_error);
  int value_;
  int low_;   // low bound of the range
  int high_;  // high bound
};

#endif
