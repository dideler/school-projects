// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.AbstractOperator.h
//
// Interface for the class AbstractOperator
// Example 6-4, 2nd version    

#ifndef EX6_4_ABSTRACTOPERATOR_H
#define EX6_4_ABSTRACTOPERATOR_H

#include "ex6.4a.node.h"
#include <string>

//class Node;
class AbstractOperator // abstract
{
 public:
  virtual double eval() const = 0;
  AbstractOperator(const std::string&);
  virtual AbstractOperator* clone() const = 0;
  std::string name() const;
  virtual ~AbstractOperator();
  void setOwner(Node*); 
 protected: 
  std::string name_;
  Node* owner_;
};

#endif 
