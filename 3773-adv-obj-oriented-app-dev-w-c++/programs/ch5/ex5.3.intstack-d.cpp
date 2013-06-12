// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.3.intstack-d.cpp 
//
// Example 5.3
// Simple test program

#include "ex5.3.intstack.h"
#include <iostream>
using namespace std;

int main()
{
  try
  {
    IntStack s(1);
    IntStack t = s;
    s.push(20);
    s.push(33);
  }
  catch(const bad_alloc&)
  {
    cout << "ran out of memory" << endl;
  }
  catch(const logic_error& e)
  {
    cout << e.what() << endl;
  }
}
