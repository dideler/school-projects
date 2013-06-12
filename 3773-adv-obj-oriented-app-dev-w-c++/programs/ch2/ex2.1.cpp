/**
 * Tomasz Muldner, September 2001
 * A program for the book:
 *  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
 *
 * Modified by Dennis Ideler, March 2013
 * Fix compile errors and make it more readable.
 *
 * File ex2.1.cpp
 * Read integer values until a positive value is entered
 * If a non-integer value is entered, abort the program
 * Otherwise, output the integer value
 */
#include <iostream>
using namespace std;

int main()
{
  int i;
  bool correct = false;
  cout << "Enter a positive integer value" << endl;

  while (cin >> i)
  {
    if (i > 0)
    {
      correct = true;
      break;
    }
    cout << "You entered a non-positive value; re-enter" << endl;
  }

  if (!correct)
    cout << "You entered a non-integer value value" << endl;
  else
    cout << "You entered " << i << endl;
}
