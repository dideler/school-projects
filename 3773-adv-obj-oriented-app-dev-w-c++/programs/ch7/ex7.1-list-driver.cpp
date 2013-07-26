// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Sample main program for Example 7-1

#include "ex7.1-list.h"
#include <iostream>
using namespace std;
using namespace LIST_ITERATION_NAMESPACE;

int main()
{
  List myList;
  int j;
  cout << "Enter 5 integers" << endl;
  for (int n = 0; n < 5; n++)
  {
    cin >> j; 
    myList.insert(j);
  }
  cout << "Enter a value to search for: ";
  cin >> j;
  for (List::ListIterator it = myList.begin(); it != myList.end(); ++it)
  {
    if (*it == j)
    {
      cout << "found" << endl;
      return 0;
    }
  }
  cout << "not found" << endl;
}
