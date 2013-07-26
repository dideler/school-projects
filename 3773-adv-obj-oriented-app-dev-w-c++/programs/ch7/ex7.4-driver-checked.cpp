// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Sample main program for a checked array

#include <iostream>
using namespace std;

#include "ex7.4-array.cpp"
#include "ex7.4-array1.cpp"
#include "ex7.4-checkedarray.cpp"
using namespace ARRAY_NAMESPACE;

int main()
{
  Array<int> x(5);
  cin >> x[1];
  Array<int>::element_type y = x[1];
  cout << y;
  Array<int> xx(x);
  cout << (x==xx) << endl;

  CheckedArray<int> c(1);
  try
  {
    c[0] = 3;
    cout << c[0] << endl;
    c[1] = 5;
  }
  catch(out_of_range e) { cerr << e.what() << endl; }
}
