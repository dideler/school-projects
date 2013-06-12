  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002

#include <iostream>
using namespace std;

#include "ex7.2.list.h"
using namespace LIST_POLYMORPHIC_ITERATION;
int main() {
  List myList;
  AbstractIterator* i = myList.makeIterator(); 
  for(int i = 0; i < 10; i++)
     myList.insert(i);
cout << "here" << endl;
  while(i->hasNext())
    cout << i->next() << endl;
  delete i;

  }

