
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.AbstractOperator.cpp
  // Implementation for the class AbstractOperator
  // Example 6-4, 2nd version   
  #include "ex6.4a.operator.h"
     
  void AbstractOperator::setOwner( Node* n) { owner_=n;} 
     
  AbstractOperator::AbstractOperator(const string& s) : name_(s), owner_(0) {}  

  string AbstractOperator::name() const { return name_; }
  AbstractOperator::~AbstractOperator() {}
