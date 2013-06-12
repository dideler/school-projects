// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex5.4.Mybenchmarkclass.h
//
// Example 5.4
// Interface for class  MyBenchmarkClass

#ifndef MYBENCHMARK_H
#define MYBENCHMARK_H
#include "ex5.4.benchmarkclass.h"

class MyBenchmarkClass : public BenchmarkClass // implements BenchmarkClass
{
 public:
  virtual void benchmark() const; // we define it in this derived class
};
#endif
