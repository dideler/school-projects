// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// Simple tester for integer wrappers
#include "ex3.4.integer.h"
#include <iostream>
using namespace std;

int main () {
  Integer i(5);
  Integer j(i);     // default copy constructor
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  j = i.set(2).add(3);
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  i = i.add(j).add(j);  // chaining: (i.add(j)).add(j)
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  Integer k = i.add(3);
  Integer m = i.add(k);
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  cout << "k = " << k.get() << "; m = " << m.get() << endl;
  m.set(3);
  cout << "i = " << i.get() << "; m = " << m.get() << endl;
}
