// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.multiplication.h
//
// Interface for the class Multiplication
// Example 6-4, 2nd version    

#ifndef EX6_4_MULTIPLICATION_H	
#define EX6_4_MULTIPLICATION_H

#include "ex6.4a.operator.h"

class Multiplication : public AbstractOperator
{
 public:
  virtual double eval() const; 
  virtual Multiplication* clone() const;
  Multiplication(const std::string&);
  virtual ~Multiplication();
};

#endif 
