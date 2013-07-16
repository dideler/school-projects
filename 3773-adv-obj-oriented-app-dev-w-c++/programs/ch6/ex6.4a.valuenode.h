// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.valuenode.h
//
// Interface for the class ValueNode
// Example 6-4, 2nd version    

#ifndef EX6_4_VALUENODE_H
#define EX6_4_VALUENODE_H

#include "ex6.4a.node.h"
#include <iostream>

class ValueNode : public Node
{
  friend class Expression;
 public: 
  ValueNode(double);
  virtual void print(std::ostream&) const;
  virtual double eval() const;
 private:
  double value_;
};

#endif
