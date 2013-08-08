// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1

#include "e8.1-company1.h"

Company1::Company1(int rep) throw (range_error) : Company2(10, rep) {}
