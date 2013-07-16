// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.function.cpp
//
// Implementation for the class Function

#include "ex6.2.function.h"
#include <string>

Function::Function(const std::string& s) : pol_(s) { }

Function::~Function() {}
