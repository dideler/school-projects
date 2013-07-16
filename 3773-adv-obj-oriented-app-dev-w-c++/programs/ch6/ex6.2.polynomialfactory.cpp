// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.polynomialfactory.cpp
//
// Implementation of class PolynomialFactory

#include "ex6.2.polynomialfactory.h"
#include "ex6.2.polynomial.h"

Polynomial* PolynomialFactory::createFunction(const string& s) const
{
  return new Polynomial(s);
}

PolynomialFactory::~PolynomialFactory() {}
