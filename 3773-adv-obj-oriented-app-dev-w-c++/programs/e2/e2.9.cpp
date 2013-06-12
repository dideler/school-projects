// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", 2002
//
// Exercise 2.9
// Write a function that returns the average of all the values stored 
// in an integer array arr of size n; the return type of this function 
// should be a double. Test this function in the main program.
//
// Refactored by D. Ideler, April 2013

#include <iostream>
using namespace std;

double average(const int arr[], int n)
{
  if (n <= 0) return -1;
  double d = arr[0];
  for (int i = 1; i < n; ++i) d += arr[i];
  return d / n;
}

int main()
{
  const int a1[] = {1, 2};
  cout << average(a1, 2) << endl;

  int a2[] = {3, 4, -1};
  cout << average(a2, 3) << endl;
}

    
