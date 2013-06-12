
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4.binarynode.h
  // Interface for class BinaryNode
  // Example 6-4, 1st version
  #ifndef EX6_4_BINARYNODE_H
  #define EX6_4_BINARYNODE_H
  #include "ex6.4.node.h"
  #include "ex6.4.expression.h"
  // represents a binary expression
  class BinaryNode : public Node {  // implements
  friend class Expression;
  public:
    BinaryNode(const string&, const Expression&, const Expression&);
    virtual void print(ostream&) const;
    virtual double eval() const;
  private:
    const string operator_;
    Expression left_;
    Expression right_;
  };
  #endif 
