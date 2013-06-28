// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.exponent.h
//
// Interface for the class Exponent
// Example 6-4, 2nd version    

#ifndef EX6_4_EXPONENT_H
#define EX6_4_EXPONENT_H

#include "ex6.4a.operator.h"
#include <string>

class Exponent : public AbstractOperator
{
 public:
  virtual double eval() const; 
  virtual Exponent* clone() const;
  Exponent(const std::string&);
  virtual ~Exponent();
};

#endif
