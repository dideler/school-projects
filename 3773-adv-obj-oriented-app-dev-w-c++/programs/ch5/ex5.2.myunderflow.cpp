// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.2.myunderflow.cpp
//
// Example 5.2
// Implementation of class My_underflow_error 

#include "ex5.2.myunderflow.h"

My_underflow_error::My_underflow_error(const string& s, int i, int j)
    : underflow_error(s), x_(i), y_(j) {}

int My_underflow_error::getArg1() const { return x_; }

int My_underflow_error::getArg2() const { return y_; }
