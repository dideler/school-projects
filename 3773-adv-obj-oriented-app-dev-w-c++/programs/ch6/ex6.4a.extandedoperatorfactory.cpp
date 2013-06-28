// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.extandedoperatorfactory.cpp
//
// Implementation for the class ExtendedOperatorFactory
// Example 6-4, 2nd version   

#include "ex6.4a.extandedoperatorfactory.h"

Exponent* ExtendedOperatorFactory::makeExponent() { return new Exponent("^"); }
