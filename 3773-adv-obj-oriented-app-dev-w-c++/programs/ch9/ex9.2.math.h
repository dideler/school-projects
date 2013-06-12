  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex9.2.math.h
  // Example 9.2
#ifndef MATH_H
#define MATH_H
#include "ex9.2.mathifc.h"
  class Math : public MathIfc { // implements
  public:
    virtual double sum(double, double) const;
    virtual double sqrt(double) const;
  };
#endif

