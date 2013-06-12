
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4.node.h
  // Example 6-4, 1st version  
  // Interface for class Node
  #ifndef EX6_4_ENODE_H
  #define EX6_4_ENODE_H
  //#include "ex6.4.expression.h"
  #include <iostream>
  class Expression;
  class Node {   // abstract
  public:
    friend class Expression;
  protected:  
    Node();
    virtual ~Node();
    virtual void print(ostream&) const = 0;
    virtual double eval() const = 0;
    
  private:
    int use_; // reference counter
  };
  #endif 

