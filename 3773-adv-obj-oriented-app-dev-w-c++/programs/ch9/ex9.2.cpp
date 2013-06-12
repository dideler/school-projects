  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Example 9.2 - sample main
#include "ex9.2.math.h"
#include <iostream>
using namespace std;

 int main() {
   MathIfc* p = new Math;
   double (MathIfc::*twoP)(double, double) = &MathIfc::sum;
   cout << (p->*twoP)(2, 3) << endl;
 }

