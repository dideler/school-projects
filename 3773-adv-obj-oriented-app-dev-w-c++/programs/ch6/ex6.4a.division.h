
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.division.h
  // Interface for the class Division
  // Example 6-4, 2nd version    
  #ifndef EX6_4_DIVISION_H
  #define EX6_4_DIVISION_H
  #include "ex6.4a.operator.h"
  class Division : public AbstractOperator { // implements Operator
  public:
    virtual double eval() const; 
    virtual Division* clone() const;
    Division(const string&);
    virtual ~Division();
  };
  #endif 
