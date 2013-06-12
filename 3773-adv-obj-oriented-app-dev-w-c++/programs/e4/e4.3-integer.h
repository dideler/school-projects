// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: e4.3-integer.h
// A wrapper class for integer values that uses instantiating operations
// plus and minus are modifiers, times and divide are queries
#ifndef EX4_3_INTEGER_H
#define EX4_3_INTEGER_H
#include <stdexcept>
class Integer {
public:
  int get() const;
  Integer& set(int);
  Integer& plus(int);
  Integer& plus(const Integer&);
  Integer& minus(int);
  Integer& minus(const Integer&);
  Integer times(int) const;
  Integer times(const Integer&) const;
  Integer divide(int) const throw(std::domain_error);
  Integer divide(const Integer&) const throw(std::domain_error);
  Integer clone() const;
  static Integer make(int);   // instantiating operation
private:
  Integer(int);
  int value_;
};
#endif

