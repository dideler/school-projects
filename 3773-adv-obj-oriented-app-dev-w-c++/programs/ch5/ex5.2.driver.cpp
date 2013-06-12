// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.2.driver.cpp
//
// Example 5.2
// Main program to test exception handling

#include <iostream>
#include <limits>
using namespace std;
#include "ex5.2.myoverflow.h"
#include "ex5.2.myunderflow.h"

int add(int x, int y) throw(My_overflow_error, My_underflow_error)
{
  if (x > 0 && y > 0 && x > numeric_limits<int>::max() - y)
    throw My_overflow_error("can't add ", x, y);
  if (x < 0 && y < 0 && x < numeric_limits<int>::min() - y)
    throw My_underflow_error("can't add", x, y);
  return x + y;
}

// This program is flawed. Because we're using ints, if you enter numbers
// larger than the max int or smaller than the min int, it'll perform
// an incorrect calculation without throwing an exception.
int main()
{
  try
  {
    cout << "max: " << numeric_limits<int>::max() << endl;
    cout << "min: " << numeric_limits<int>::min() << endl;
    int x, y;
    cout << "enter two integers: ";
    cin >> x >> y;
    cout << endl << x << " + " << y << " = " << add(x, y) << endl;
  }
  catch(const My_overflow_error& exc)
  {
    cerr << exc.what() << exc.getArg1() << " " << exc.getArg2() << endl;
  }
  catch(const My_underflow_error& exc)
  {
    cerr << exc.what() << exc.getArg1() << " " << exc.getArg2() << endl;
  }
}
