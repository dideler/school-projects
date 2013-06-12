
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.expression.cpp
  // Implementation for the class Expression
  // Example 6-4, 2nd version   
  #include <iostream>
  #include <string>
  using namespace std;

  #include "ex6.4a.expression.h"
  #include "ex6.4a.valuenode.h"
  #include "ex6.4a.unarynode.h"
  #include "ex6.4a.binarynode.h"

  Expression::Expression(double num) {
    rep_ = new ValueNode(num);
 }

  Expression::Expression(AbstractOperator* op, const Expression& t) {
    rep_ = new UnaryNode(op, t);
  }

  Expression::Expression(AbstractOperator* op,
      const Expression& t1, const Expression& t2) {
    rep_ = new BinaryNode(op, t1, t2);
  }

  Expression::Expression(const Expression& t) {
    rep_ = t.rep_;
    ++rep_->use_;
  }

  Expression::~Expression() {
    if(--rep_->use_ == 0)
      delete rep_;
  }

  Expression& Expression::operator=(const Expression& rhs) {
    if(this == &rhs)
      return *this;
    ++rhs.rep_->use_;
    if(--rep_->use_ == 0)
      delete rep_;
    rep_= rhs.rep_;
    return *this;
  }

  void Expression::print(ostream& os) const {
    rep_->print(os);
   // os << endl;
  }

  double Expression::eval() const {
    return rep_->eval();
  }
