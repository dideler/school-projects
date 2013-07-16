// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.valuenode.cpp
//
// Implementation for the class ValueNode
// Example 6-4, 2nd version   

#include "ex6.4a.valuenode.h"

ValueNode::ValueNode(double v) : value_(v) {}

void ValueNode::print(std::ostream& st) const { st << value_; }

double ValueNode::eval() const { return value_; }
