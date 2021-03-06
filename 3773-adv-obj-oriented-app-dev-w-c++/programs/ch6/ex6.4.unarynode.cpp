// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4.unarynode.cpp
//
// Exercise 6-4, 1st version    
// Implementation for the class UnaryNode

#include "ex6.4.unarynode.h"
#include <stdexcept>

UnaryNode::UnaryNode(const std::string& op, const Expression& t)
    : operator_(op), operand_(t) {}

void UnaryNode::print(std::ostream& st) const
{
  st << "(" << operator_ << " ";
  operand_.print(st);
  st << ")";
}

double UnaryNode::eval() const
{
  if (operator_ == "-") return -operand_.eval();
  throw std::invalid_argument("invalid unary operator");
}
