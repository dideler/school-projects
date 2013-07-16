// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4.expression.cpp
//
// Exercise 6-4, 1st version    
// Implementation for the class Expression

#include "ex6.4.expression.h"
#include "ex6.4.valuenode.h"
#include "ex6.4.unarynode.h"
#include "ex6.4.binarynode.h"
#include <iostream>
#include <string>
using namespace std;

Expression::Expression(double num) { rep_ = new ValueNode(num); }

Expression::Expression(const string& op, const Expression& t)
{
  rep_ = new UnaryNode(op, t);
}

Expression::Expression(const string& op, const Expression& t1,
                       const Expression& t2)
{
  rep_ = new BinaryNode(op, t1, t2);
}

Expression::Expression(const Expression& t)
{
  rep_ = t.rep_;
  ++rep_->use_;
}

Expression::~Expression() { if (--rep_->use_ == 0) delete rep_; }

Expression& Expression::operator=(const Expression& rhs)
{
  if (this == &rhs) return *this;
  ++rhs.rep_->use_;
  if (--rep_->use_ == 0) delete rep_;
  rep_= rhs.rep_;
  return *this;
}

void Expression::print(ostream& os) const { rep_->print(os); }

double Expression::eval() const { return rep_->eval(); }
