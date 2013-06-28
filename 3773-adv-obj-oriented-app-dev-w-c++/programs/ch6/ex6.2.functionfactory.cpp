// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.functionfactory.cpp
//
// Implementation for the class FunctionFactory

#include "ex6.2.functionfactory.h"
#include "ex6.2.polynomialfactory.h"
#include "ex6.2.rationalfactory.h"
#include <string>
using std::string;

FunctionFactory* FunctionFactory::getFactory(const string& s)
{
  string::size_type pos = s.find_first_of('/');
  if (pos == string::npos) // if s represents a polynomial
    return new PolynomialFactory();
  return new RationalFactory();
}

FunctionFactory::~FunctionFactory() {}
