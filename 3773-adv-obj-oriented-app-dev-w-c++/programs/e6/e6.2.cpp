// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Example 6.2
// File: e6.2.intstack-d.cpp 
//
// Simple test program

#include "e6.2.der-intstack.h"
#include <iostream>
using namespace std;

int main()
{
  try
  {
    DerIntStack s(1);
    cout << "new stack is " << (s.empty() ? "" : "not ") << "empty" << endl;
    s.push(20);
    cout << "after push, stack is " << (s.full() ? "" : "not ") << "full" << endl;  
    cout << "popping : " << s.pop() << endl;
    cout << "now stack is " << (s.empty() ? "" : "not ") << "empty" << endl;   
    s.push(33);
    s.push(2); // throws exception
  }
  catch(const bad_alloc&) { cout << "ran out of memory" << endl; }
  catch(const logic_error& e) { cout << e.what() << endl; }
}
