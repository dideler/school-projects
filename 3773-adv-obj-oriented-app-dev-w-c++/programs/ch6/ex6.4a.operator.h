
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.AbstractOperator.h
  // Interface for the class AbstractOperator
  // Example 6-4, 2nd version    
  #ifndef EX6_4_ABSTRACTOPERATOR_H
  #define EX6_4_ABSTRACTOPERATOR_H
  //class Node;
  #include "ex6.4a.node.h"
  #include <string>
  class AbstractOperator {  // abstract
  public:
    virtual double eval() const = 0;
    AbstractOperator(const string&);
    virtual AbstractOperator* clone() const = 0;
    string name() const;
    virtual ~AbstractOperator();
    void setOwner(Node*); 
  protected: 
    string name_;
    Node* owner_;
  };
  #endif 
