// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", 2002
//
// Exercise 2.3 (slightly different from book)
// Write a program that reads integer values from standard input and writes 
// to standard output the smallest of the input values and the average input value. 
// Reading should stop when either a value equal to -1, or greater than 100, 
// is encountered; it should also stop when an incorrect integer value is entered. 
// If there is no integer value in the input, the program should output the 
// following message "no integer values found". 
//
// Refactored by D. Ideler, April 2013
#include <iostream>
using namespace std;

int main()
{
  int smallest;
  int count = 0;
  int sum = 0;
  cout << "Enter integer values, to stop enter -1 or a value > 100" << endl;

  for (int i; cin >> i; ++count, sum += i)
  {
    if (i == -1 || i > 100)
      break;
    if (count == 0) 
      smallest = i;
    else if (i < smallest)
      smallest = i;
  }

  if (count == 0)
    cout << "no integer values found" << endl;
  else 
    cout << "smallest = " << smallest << "; average = " << sum / static_cast<double>(count) << endl;
}
