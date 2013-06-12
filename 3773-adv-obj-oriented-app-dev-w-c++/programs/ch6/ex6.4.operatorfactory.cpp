
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4.operatorfactory.cpp
  // Exercise 6-4, 1st version    
  // Implementation for the class OperatorFactory

  #include "ex6.4.operatorfactory.h"
  Operator* OperatorFactory::makePlus() {
    return new Addition;
  }

    Times* OperatorFactory::makeTimes() {
       return new Multiplication;
    }
    Minus* OperatorFactory::makeMinus() {
       return new Subtraction;
    }
    Divide* OperatorFactory::makeDivide() { 
       return new Division;
    }

