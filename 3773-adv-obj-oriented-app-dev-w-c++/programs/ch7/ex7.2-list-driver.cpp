// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Sample main program for example 7.2. Similar to example 7.1,
// but uses a polymorphic (list) iterator, i.e. iterator has an abstract class.

#include "ex7.2-list.h"
#include "ex7.2-iterator.h"
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace LIST_POLYMORPHIC_ITERATION;

int main()
{
  List myList;
  int j;
  cout << "Enter five integers" << endl;
  for (int n = 0; n < 5; n++)
  {
    cin >> j; 
    myList.insert(j);
  }
  cout << "Enter a value to search for: ";
  cin >> j;
  AbstractIterator* iter = myList.makeIterator(); // returns concrete list
  try
  {
    while (iter->hasNext())
    {
      if (iter->next() == j)
      {
        cout << "found" << endl;
        return 0;
      }
    }
  }
  catch(range_error& e) { cout << e.what() << endl; }
  cout << "not found" << endl;
}
