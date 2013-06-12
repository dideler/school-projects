  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.14
#include <iostream>
using namespace std;
#include <list>
template <typename T>
list<T> concatenate(const list<T>& one, const list<T>& two) {
  list<T> head(one.begin(), one.end());
  list<T> temp(two.begin(), two.end());
  head.splice(head.end(), temp);
  return head;
} 
  int main() {
    list<int> one;
    list<int> two;
    for(int i = 0; i < 10; ++i) {
      one.insert(one.end(), i);
      two.insert(two.end(), 10-i);
   }
    for(list<int>::iterator i = one.begin(); i != one.end(); ++i)
     cout << *i << " ";
   cout << endl;
 for(list<int>::iterator i = two.begin(); i != two.end(); ++i)
     cout << *i << " ";
   cout << endl;
   list<int> three = concatenate(one, two);
   for(list<int>::iterator i = three.begin(); i != three.end(); ++i)
     cout << *i << " ";
   cout << endl;
    
  }
