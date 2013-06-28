// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4.valuenode.cpp
//
// Exercise 6-4, 1st version    
// Implementation for the class ValueNode

#include "ex6.4.valuenode.h"

ValueNode::ValueNode(double v) : value_(v) {}

void ValueNode::print(std::ostream& st) const { st << value_; }

double ValueNode::eval() const { return value_; }
