// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.subtraction.cpp
//
// Implementation for the class Subtraction
// Example 6-4, 2nd version   

#include "ex6.4a.subtraction.h"
#include "ex6.4a.binarynode.h"
#include <cstdlib>

double Subtraction::eval() const
{
  BinaryNode* p;
  p = dynamic_cast<BinaryNode*>(owner_);
  if (p == 0)
  {
    std::cerr << "this cannot happen" << std::endl;
    exit(1);
  } 
  return p->getLeft() - p->getRight();
}

Subtraction* Subtraction::clone() const { return new Subtraction(*this); }

Subtraction::~Subtraction() {} 

Subtraction::Subtraction(const std::string& n) : AbstractOperator(n) {}
