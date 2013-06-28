// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4.unarynode.h
//
// Example 6-4, 1st version
// Interface for class UnaryNode

#ifndef EX6_4_UNARYNODE_H
#define EX6_4_UNARYNODE_H

#include "ex6.4.node.h"
#include "ex6.4.expression.h"
#include <string>

// represents a unary node
class UnaryNode : public Node
{
  friend class Expression;
 public: 
  UnaryNode(const std::string&, const Expression&);
  virtual void print(std::ostream&) const;
  virtual double eval() const;
 private:
  const std::string operator_;
  Expression operand_;
};

#endif
