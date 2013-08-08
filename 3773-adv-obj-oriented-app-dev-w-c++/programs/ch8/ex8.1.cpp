// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1
//
// Simple test of shellsort

#include <iostream>
using namespace std;

#include "ex8.1.shellsort.cpp"

int main()
{
  int x[] = {4, 2, 5, 1, 3};
  shellSort(x, x+5);
  for (int i = 0; i < 5; ++i)
    cout << x[i] << ' ';
  cout << endl;
}
