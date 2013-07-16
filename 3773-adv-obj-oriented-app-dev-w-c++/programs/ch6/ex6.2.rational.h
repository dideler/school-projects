// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.rational.h

#ifndef EX6_2_RATIONAL_H
#define EX6_2_RATIONAL_H

#include <string>
#include "ex6.2.function.h"

class Rational : public Function
{
 public:
  virtual void display() const;
  Rational(const std::string&);
  virtual ~Rational();
 private:
  int* nomCoefficients_;
  int nomDegree_;
  int* denCoefficients_;
  int denDegree_;
};

#endif
