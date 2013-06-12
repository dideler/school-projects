// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.4.benchmarkclass.cpp
//
// Example 5.4
// Implementation of class BenchmarkClass

#include <ctime>
#include "ex5.4.benchmarkclass.h"

// Notice that benchmark() has no definition.

double BenchmarkClass::repeat(long count) const
{
  time_t start, finish;
  time(&start);
  for (long loop = 0; loop < count; ++loop)
    benchmark();
  time(&finish);
  return difftime(finish, start);
}
