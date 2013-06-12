
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.unarynode.cpp
  // Implementation for the class UnaryNode
  // Example 6-4, 2nd version   
  #include "ex6.4a.unarynode.h"
  #include "ex6.4a.operator.h"

  UnaryNode::UnaryNode(AbstractOperator* op, const Expression& t): 
    operand_(t) { 
    operator_ = op->clone();
    operator_->setOwner(this);
  }

  void UnaryNode::print(ostream& st) const { 
    st << "(" << operator_->name() << " ";
    operand_.print(st);
    st << ")";
  }

  double UnaryNode::eval() const { 
    return operator_->eval();
  }

 double UnaryNode::getValue() const {
  return operand_.eval();
}

  UnaryNode::~UnaryNode() {
      delete operator_;
   }
