
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.binarynode.cpp
  // Implementation for the class BinaryNode
  // Example 6-4, 2nd version   
  #include "ex6.4a.binarynode.h"
  #include "ex6.4a.operator.h"
  #include "ex6.4a.addition.h"
  BinaryNode::BinaryNode(AbstractOperator* op,
    const Expression& t1, const Expression& t2):
      left_(t1), right_(t2) { 
     operator_ = op->clone();
     operator_->setOwner(this);
  }

  void BinaryNode::print(ostream& st) const {
    st << "(";
    left_.print(st);
    st << " " << operator_->name() << " ";
    right_.print(st);
    st << ")";
  }

  double BinaryNode::eval() const { 
    return operator_->eval();
  }

  BinaryNode::~BinaryNode() {
    delete operator_;
 }
 double BinaryNode::getLeft() const {
    return left_.eval();
 }
 double BinaryNode::getRight() const {
   return right_.eval();
 }

