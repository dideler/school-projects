  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Sample main program for Exercise 7-5
  // File: e7.5.cpp
#include "e7.5-list.h"
#include <iostream>
using namespace std;
using namespace LIST_ITERATION_NAMESPACE;
void show(List& h) {
   cout << "showing list of size:" << h.size() << endl;
   for(List::ListIterator it = h.begin(); it != h.end(); ++it)    
     cout << *it << " ";
   cout << endl;
}


int main() {  

  List myList;
  int j;
  // create a simple list
  for(int n = 0; n < 4; n++) 
    myList.insert(n);
  show(myList);
  
  // try remove
  myList.removeFirst(j);
  cout << "value removed = " << j << endl;
  show(myList); 
  List h;
  try {
    h.removeFirst(j);
  } catch(domain_error& e) {
    cout << e.what() << endl;
  }
  // try insert and remove
  List::ListIterator it = myList.begin();
  try {
    // these should not throw
    it.remove(j);
    cout << "value removed = " << j << endl; 
     show(myList);   
  } catch(domain_error& e) {
    cout << e.what() << endl;
  }    
  List::ListIterator it1 = myList.begin();  
  try {
    // these should not throw 
    cout << "insertBefore 22" << endl;
    it1.insertBefore(22);
    show(myList);
    cout << "insertAfter 33" << endl;
    it1.insertAfter(33);
    show(myList); 
    cout << "incrementing iterator" << endl;
    ++it1;
    cout << "insertBefore 24" << endl; 
    it1.insertBefore(24);
    show(myList);
    it1.insertAfter(34);
    cout << "insertAfter 34" << endl;
    show(myList);    
  } catch(domain_error& e) {
    cout << e.what() << endl;
  } 
}
