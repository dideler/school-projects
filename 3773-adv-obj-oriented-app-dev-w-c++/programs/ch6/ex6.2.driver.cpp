
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Example 6-2
  // Sample main program for a function factory
 #include <iostream>
 using namespace std;
 #include "ex6.2.polynomial.h"
 #include "ex6.2.rational.h"
 #include "ex6.2.polynomialfactory.h"
 #include "ex6.2.rationalfactory.h"
 #include "ex6.2.functionfactory.h" 
 #include "ex6.2.functionfactory.h"
int main() {
  string s;
  cout << "enter string ";
  getline(cin, s);
  FunctionFactory* factory = FunctionFactory::getFactory(s);
  Function* foo = factory->createFunction(s);
  foo->display();
}

