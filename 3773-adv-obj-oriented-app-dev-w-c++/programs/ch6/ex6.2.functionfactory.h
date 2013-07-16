// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.functionfactory.h

#ifndef EX6_2_FUNCTIONFACTORY_H
#define EX6_2_FUNCTIONFACTORY_H

#include "ex6.2.function.h"
#include <string>
using std::string;

class FunctionFactory
{
 public:
  virtual Function* createFunction(const string&) const = 0;
  static FunctionFactory* getFactory(const string&);
  virtual ~FunctionFactory();
};

#endif
