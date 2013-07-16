// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.polynomialfactory.h

#ifndef EX6_2_POLYNOMIALFACTORY_H
#define EX6_2_POLYNOMIALFACTORY_H

#include "ex6.2.functionfactory.h"
#include "ex6.2.polynomial.h" 
//  #include "ex6.2.polynomialfactory.h"

class PolynomialFactory : public FunctionFactory
{
 public:
  virtual Polynomial* createFunction(const std::string&) const;
  virtual ~PolynomialFactory();
};

#endif
