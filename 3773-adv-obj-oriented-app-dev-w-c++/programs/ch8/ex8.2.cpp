  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.2
  // File: ex8.2.cpp
#include "ex8.2.isprime.cpp"

#include <iostream>
using namespace std;

int main() {
  int x[4] = {2, 5, 7, 11};
  if(find_if(x, x+4, not1(isPrime())) == x+4) cout << "not found in x" << endl;
  int z[4] = {2, 8, 7, 11};
  if(find_if(z, z+4, not1(isPrime())) == x+4) cout << "not found in z" << endl; 
}

