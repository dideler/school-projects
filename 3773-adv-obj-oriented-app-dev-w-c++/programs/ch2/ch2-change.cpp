// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ch2-change.cpp
//
// Modified and completed by Dennis Ideler, March 2013

// Returns a pointer to the p-th element.
int* pointerToElement(int arr[], int size, int p)
{
  if (p < 0 || p >= size) return 0;  // error
  return &arr[p];
}

// Returns a const pointer to the p-th element.
// Note that the arr parameter doesn't have to be const, but it may as well be.
const int* constPointerToElement(const int arr[], int size, int p)
{
  if (p < 0 || p >= size) return 0;  // error
  return &arr[p];
}

#include <iostream>
using namespace std;

int main()
{
  int x[] = {1, 2, 3};
  
  // With a pointer to an element, we can read and write.
  int* i = pointerToElement(x, 3, 2);
  cout << "*i = " << *i << endl;
  *i = 0;  // OK, can modify through i
  cout << "*i = " << *i << endl;

  // With a const pointer, we can only read.
  const int *j = constPointerToElement(x, 3, 2);
  cout << "*j = " << *j << endl;
  //*j = 3; // Error: assignment of read-only location
            //        can't assign to a const
  //i = nonChangeable(x, 3, 2); // Error: invalid conversion from ‘const int*’ to ‘int*’
                                //        can't assign const to a non-const
}
