
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4.ternarynode.cpp
  // Exercise 6-4, 1st version    
  // Implementation for the class TernaryNode
  #include "ex6.4.ternarynode.h"

  TernaryNode::TernaryNode(const string& op, const Expression& a,
     const Expression& b, const Expression& c): operator_(op), 
      left_(a), middle_(b), right_(c)  {}

  void TernaryNode::print(ostream& st) const {
    st << operator_ << "(";
    left_.print(st);
    st << ", ";
    middle_.print(st);
    st  << ", ";
    right_.print(st);
    st << ")";
  }

  void TernaryNode::eval() const {
    if(operator_ == "?:") {
      if(left_.eval() return middle_.eval();
      return right_.eval(); 
    }
    throw invalid_argument("invalid binary operator");
  }
