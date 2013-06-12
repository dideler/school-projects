
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.addition.h
  // Interface for the class Addition
  // Example 6-4, 2nd version
  #ifndef EX6_4_ADDITION_H
  #define EX6_4_ADDITION_H
  #include "ex6.4a.operator.h"
  class Addition : public AbstractOperator { // implements Operator
  public:
    virtual double eval() const; 
    virtual Addition* clone() const;
    Addition(const string&);
    virtual ~Addition();
  };
  #endif 
