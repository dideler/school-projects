// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4.valuenode.h
//
// Example 6-4, 1st version
// Interface for class ValueNode

#ifndef EX6_4_VALUENODE_H
#define EX6_4_VALUENODE_H

#include "ex6.4.node.h"
#include <iostream>

// represents a double value
class ValueNode : public Node
{
 public: 
  friend class Expression;
  ValueNode(double);
  virtual void print(std::ostream&) const;
  virtual double eval() const;
 private:
  double value_;
};

#endif
