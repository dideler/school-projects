
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4.binarynode.cpp
  // Exercise 6-4, 1st version    
  // Implementation for the class BinaryNode
  #include <string>
  #include <iostream>
  #include <stdexcept>
  #include "ex6.4.binarynode.h"
  BinaryNode::BinaryNode(const string& op,
    const Expression& t1, const Expression& t2):
      operator_(op), left_(t1), right_(t2) { }

  void BinaryNode::print(ostream& st) const {
    st << "(";
    left_.print(st);
    st << " " << operator_ << " ";
    right_.print(st);
    st << ")";
  }

  double BinaryNode::eval() const { 
      // *,-,+,/
    if(operator_ == "+") return left_.eval() + right_.eval(); 
    if(operator_ == "-") return left_.eval() - right_.eval(); 
    if(operator_ == "*") return left_.eval() * right_.eval();
    if(operator_ == "/") {
      double v = right_.eval();
      if(v == 0)
        throw invalid_argument("dividing by zero");
      return left_.eval() / v;
    }
    throw invalid_argument("invalid binary operator");
  }
