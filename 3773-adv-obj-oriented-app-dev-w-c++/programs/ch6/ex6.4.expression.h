
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4.expression.h
  // Interface for class Expression
  // Example 6-4, 1st version  
  #ifndef EX6_4_EXPRESSION_H
  #define EX6_4_EXPRESSION_H
  // #include "ex6.4.node.h"
  #include <string>
  class Node; // declaration
  class Expression {
  public: 
    friend class Node;
    // constructors for values and sub-expressions
    Expression(double);// single value
    Expression(const string&, const Expression&); // unary
    Expression(const string&, const Expression&, const Expression&); //binary
    // copy constructor, assignment and destructor
    Expression(const Expression&); 
    Expression& operator=(const Expression&); 
    virtual ~Expression();
    // output and evaluation functions
    virtual void print(ostream&) const;
    virtual double eval() const;
  private:
    Node* rep_;  // delegate to Node
  };
  #endif 
