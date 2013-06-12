// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// Simple tester for integer wrapper.

#include "e4.3-integer.h"
#include <iostream>
using namespace std;

int main ()
{
  Integer i = Integer::make(5); // using instantiating operation
  Integer j = i.clone(); // instead of copy constructor
  cout << "i and j should be both 5" << endl;
  cout << "i = " << i.get() << "; j = " << i.get() << endl;

  i = i.set(2); // just `i.set(2)` also works
  j.plus(3); // j = 5 + 3 = 8
  cout << "\ni should be 2, and j should be 8" << endl;
  cout << "i = " << i.get() << "; j = " << j.get() << endl;

  i = i.plus(j).plus(j);  // chaining operations; i = 2 + 8 + 8
  cout << "\ni should be 18, and j is still 8" << endl;
  cout << "i = " << i.get() << "; j = " << j.get() << endl;

  Integer k = i.plus(3); // k = i = 18 + 3 = 21
  Integer m = i.plus(k); // m = i = 21 + 21 = 42
  cout << "\ni should be 42, j is the same as before, k is 21, m is same as i" << endl;
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  cout << "k = " << k.get() << "; m = " << m.get() << endl;

  i = j.minus(3); // i = 8 - 3 = 5
  k = j.times(3); // k = 5 * 3 = 15 (times and divide are queries)
  m = j.divide(3); // m = 5 / 3 = 1 (integer division)
  cout << "\ni is 5, k is 15, j is 5, m is 1" << endl;
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  cout << "k = " << k.get() << "; m = " << m.get() << endl;

  cout << "\ntry to divide by 0" << endl;
  try
  {
    m.set(0);
    i = k.divide(m);
  }
  catch( domain_error& e) { cout << e.what() << endl; } 
}
