// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Example 5.4
// Simple test program

#include "ex5.4.mybenchmarkclass.h"
#include "ex5.4.benchmarkclass.h"
#include <iostream>
using namespace std;

int main()
{
  BenchmarkClass* b1 = new MyBenchmarkClass();
  cout << "~" << b1->repeat(1000000000) << " sec" << endl;

  MyBenchmarkClass b2;
  cout << "~" << b2.repeat(1000000000) << " sec" << endl;
}
