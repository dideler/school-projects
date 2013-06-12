// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.1.bank.cpp
//
// Example 5.1
// Implementation of class Bank

#include "ex5.1.bank.h"
#include <string>

Bank::Bank(const string& s) : name_(s) {}

string Bank::getName() const { return name_; }
