// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.extandedoperatorfactory.h
//
// Interface for the class ExtendedOperatorFactory
// Example 6-4, 2nd version    

#ifndef EX6_4_EXTENDEDOPERATORFACTORY_H
#define EX6_4_EXTENDEDOPERATORFACTORY_H

#include "ex6.4a.operatorfactory.h"
#include "ex6.4a.exponent.h"

class ExtendedOperatorFactory : public OperatorFactory
{
 public:
  static Exponent* makeExponent();
};

#endif 
