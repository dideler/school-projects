// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.rationalfactory.h

#ifndef EX6_2_RATIONALFACTORY_H
#define EX6_2_RATIONALFACTORY_H

//#include "ex6.2.rationalfactory.h"
#include "ex6.2.functionfactory.h"
#include "ex6.2.rational.h"
#include <string>

class RationalFactory : public FunctionFactory
{
 public:
  virtual Rational* createFunction(const string&) const;
  virtual ~RationalFactory();
};

#endif
