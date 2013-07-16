// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.addition.cpp
//
// Exercise 6-4, 1st version
// Implementation for the class Addition

#include "ex6.4a.addition.h"
#include "ex6.4a.binarynode.h"
#include <cstdlib>

double Addition::eval() const
{
  BinaryNode* p;
  p = dynamic_cast<BinaryNode*>(owner_);
  if (p == 0) {
    std::cerr << "this cannot happen" << std::endl;
    exit(1);
  } 
  return p->getLeft() + p->getRight();
}

Addition* Addition::clone() const { return new Addition(*this); }

Addition::~Addition() {} 

Addition::Addition(const std::string& n) : AbstractOperator(n) {}
