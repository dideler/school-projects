// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Sample main program for example 7-5.

#include <iostream>
using namespace std;

#include "ex7.4-array.cpp"
#include "ex7.4-array1.cpp"
using namespace ARRAY_NAMESPACE;

int main()
{
  cout << "Enter an integer: ";
  Array<int> x(5);
  cin >> x[1];
  Array<int>::element_type y = x[1];
  cout << y;
  Array<int> xx(x);
  cout << endl << (x==xx) << endl;
}
