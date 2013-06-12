// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// Simple tester for the intgeer stack class
#include "ex3.5.intstack.h"
#include <iostream>
using namespace std;

int main()
{

  IntStack s(2), t = s;

  t.push(20);
  if (t.getError() == IntStack::STACK_FULL) {
    cout << "can't push, stack full\n";
  }
  cout << t.top() << endl;

  t.push(10);
  if (t.getError() == IntStack::STACK_FULL) {
    cout << "can't push, stack full\n";
  }
  cout << t.top() << endl;

  t.push(20);
  if (t.getError() == IntStack::STACK_FULL) {
    cout << "can't push, stack full\n";
    t.clearError();
  }
  cout << t.top() << endl; 

  t.pop();
  if (t.getError() == IntStack::STACK_EMPTY) {
    cout << "can't pop, stack empty\n";
    t.clearError();
  }
  cout << t.top() << endl;
}
