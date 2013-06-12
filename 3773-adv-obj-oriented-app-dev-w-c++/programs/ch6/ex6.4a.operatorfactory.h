  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.operatorfactory.h
  // Interface for the class OperatorFactory
  // Example 6-4, 2nd version    
  #ifndef EX6_4_OPERATORFACTORY_H
  #define EX6_4_OPERATORFACTORY_H

  #include "ex6.4a.addition.h"
  #include "ex6.4a.division.h"
  #include "ex6.4a.multiplication.h"
  #include "ex6.4a.subtraction.h"
  class OperatorFactory {
  public:
   static Addition* makeAddition();
   static Multiplication* makeTimes();
   static Subtraction* makeMinus();
   static Division* makeDivide();
  };
  #endif 
