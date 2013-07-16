// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.polynomial.h

#ifndef EX6_2_POLYNOMIAL_H
#define EX6_2_POLYNOMIAL_H

#include "ex6.2.function.h"

class Polynomial : public Function
{
 public:
  virtual void display() const;
  Polynomial(const std::string&);
  virtual ~Polynomial();
 private:
  double* coefficients_;
  int degree_;
};

#endif
