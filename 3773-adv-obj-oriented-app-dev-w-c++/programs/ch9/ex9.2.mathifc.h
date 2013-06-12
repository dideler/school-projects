  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  //File: ex9.2.mathifc.h
  // Example 9.2
#ifndef MATHIFC_H
#define MATHIFC_H
  class MathIfc { // interface
  public:
    virtual double sum(double, double) const = 0;
    virtual double sqrt(double) const = 0;
  };
#endif

