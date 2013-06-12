
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.unarynode.h
  // Interface for the class UnaryNode
  // Example 6-4, 2nd version    
  #ifndef EX6_4_UNARYNODE_H
  #define EX6_4_UNARYNODE_H
  #include "ex6.4a.node.h"
  #include "ex6.4a.expression.h"
  class AbstractOperator;
  class UnaryNode : public Node {  
	  friend class Expression;
  public: 
    UnaryNode(AbstractOperator*, const Expression&);
    ~UnaryNode();
    virtual void print(ostream&) const;
    virtual double eval() const;
    double getValue() const;
  private:
    Expression operand_;
    AbstractOperator* operator_; 
  };
  #endif
