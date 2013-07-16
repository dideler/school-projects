// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.operatorfactory.cpp 
//
// Implementation for the class OperatorFactory
// Example 6-4, 2nd version   

#include "ex6.4a.operatorfactory.h"

Addition* OperatorFactory::makeAddition() { return new Addition("+"); }

Multiplication* OperatorFactory::makeTimes() { return new Multiplication("*"); }

Subtraction* OperatorFactory::makeMinus() { return new Subtraction("-"); }

Division* OperatorFactory::makeDivide() { return new Division("/"); }
