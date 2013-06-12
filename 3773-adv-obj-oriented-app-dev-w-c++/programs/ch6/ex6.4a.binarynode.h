
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.binarynode.h
  // Interface for the class BinaryNode
  // Example 6-4, 2nd version    
  #ifndef EX6_4_BINARYNODE_H
  #define EX6_4_BINARYNODE_H
  #include "ex6.4a.node.h"
  #include "ex6.4a.expression.h"
  class Expression;
  class BinaryNode : public Node {
    friend class Expression;
  public:

    BinaryNode(AbstractOperator*, const Expression&, const Expression&);
    virtual void print(ostream&) const;
    virtual double eval() const;
    ~BinaryNode();
    double getLeft() const;
    double getRight() const;
  private:
    Expression left_;
    Expression right_;
    AbstractOperator* operator_;
  };
  #endif 
