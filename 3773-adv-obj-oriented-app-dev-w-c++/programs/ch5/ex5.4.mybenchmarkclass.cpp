// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex5.4.Mybenchmarkclass.cpp
//
// Example 5.4
// Implementation of class MyBenchmark

#include "ex5.4.mybenchmarkclass.h" 

// Multiplcation with floating point numbers as a benchmark.
void MyBenchmarkClass::benchmark() const { double res = 1.23 * 4.56; }
