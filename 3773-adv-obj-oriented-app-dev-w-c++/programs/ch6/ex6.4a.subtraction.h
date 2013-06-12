
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.subtraction.h
  // Interface for the class Subtraction
  // Example 6-4, 2nd version    
  #ifndef EX6_4_SUBTRACTION_H
  #define EX6_4_SUBTRACTION_H
  #include "ex6.4a.operator.h"
  class Subtraction : public AbstractOperator { // implements Operator
  public:
    virtual double eval() const; 
    virtual Subtraction* clone() const;
    Subtraction(const string&);
    virtual ~Subtraction();
  };
  #endif 
