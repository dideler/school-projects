
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // File: ex8.1.cpp 
  // Simple test of shellsort
#include "ex8.1.shellsort.cpp"
#include <iostream>
int main() {
  int x[] = {4, 2,5, 1 };
  shellSort(x, x+4);
  for(int i=0;i<4;++i) cout << x[i] << endl;
}                    

