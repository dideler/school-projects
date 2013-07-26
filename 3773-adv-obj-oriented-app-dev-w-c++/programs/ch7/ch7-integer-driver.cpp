// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Section 7.3, page 286

#include "ch7-integer.h"
#include <iostream>
using namespace std;

int main()
{
  try
  {
    Integer a(2);
    Integer b(4);
    int c = a + b;
    cout << c << endl;
    Integer i(2, 0, 5); // range [0,5]
    Integer j(4, 0, 5);
    i = i + j; // will throw exception; 2+4 > 5
  } catch(range_error& e) { cout << e.what() << endl; }
}
