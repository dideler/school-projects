// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ch2-index.cpp
//
// Modified by Dennis Ideler, March 2013

// Gives read/write access to the i-th element of array x.
// Pass by reference.
int& index(int x[], int i) { return x[i]; }

// Gives read access to the i-th element of array x.
// Pass by constant reference.
const int& get(const int x[], int i) { return x[i]; }

#include <iostream>
using namespace std;

int main()
{
  int a[5]; 
  cout << "enter 5 values " << endl;

  for (int i = 0; i < 5; i++)
    cin >> index(a, i); // use index() for write access

  cout << "array is: ";
  for (int i = 0; i < 5; i++)
    cout << index(a, i) << "\t"; // use index() for read access

  cout << endl << "array is: ";
  for (int i = 0; i < 5; i++)  
     cout << get(a, i) << "\t"; // use get() for read access
  cout << endl;
}

