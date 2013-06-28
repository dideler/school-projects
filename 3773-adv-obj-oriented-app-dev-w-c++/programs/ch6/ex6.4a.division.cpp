// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.division.cpp
//
// Implementation for the class Division
// Example 6-4, 2nd version   

#include "ex6.4a.division.h"
#include "ex6.4a.binarynode.h"
#include <cstdlib>

double Division::eval() const
{
  BinaryNode* p;
  p = dynamic_cast<BinaryNode*>(owner_);
  if (p == 0)
  {
    std::cerr << "this cannot happen" << std::endl;
    exit(1);
  } 
  return p->getLeft() / p->getRight();
}

Division* Division::clone() const { return new Division(*this); }

Division::~Division() {}

Division::Division(const std::string& n) : AbstractOperator(n) {}
