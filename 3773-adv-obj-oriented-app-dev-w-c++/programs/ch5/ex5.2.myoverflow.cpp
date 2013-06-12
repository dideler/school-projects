// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.2.myoverflow.cpp
//
// Example 5.2
// Implementation of class My_overflow_error 

#include "ex5.2.myoverflow.h"

My_overflow_error::My_overflow_error(const string& s, int i, int j)
    : overflow_error(s), x_(i), y_(j) {}

int My_overflow_error::getArg1() const { return x_; }

int My_overflow_error::getArg2() const { return y_; }
