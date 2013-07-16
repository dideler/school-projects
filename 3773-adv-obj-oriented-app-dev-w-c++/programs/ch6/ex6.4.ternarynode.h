// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4.ternarynode.h
//
// Example 6-4, 1st version
// Interface for class Ternary_Node    

#ifndef EX6_4_TERNARY_NODE
#define EX6_4_TERNARY_NODE

#include "ex6.4.node.h"

class Ternary_Node : public Node
{
  friend class Expression;
 public:
  Ternary_Node(const std::string&, const Expression&, const Expression&,
               const Expression&);
  virtual void print(std::ostream&) const;
  virtual double eval() const;
 private:
  const std::string operator_;
  Expression left_;
  Expression middle_;
  Expression right_;
};

#endif
