// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.4.benchmarkclass.cpp
//
// Example 5.4
// Interafce for class BenchmarkClass 

#ifndef BENCHMARK_H
#define BENCHMARK_H  
class BenchmarkClass // abstract (base) class, due to pure virtual function
{
 public:
  virtual void benchmark() const = 0; // declaration, but no definition
  double repeat(long count) const;
};
#endif
