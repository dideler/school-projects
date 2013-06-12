  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Sample main program for Exercise 7-3
#include <iostream>
using namespace std;
#include "ex7.3.stack.cpp"
int main() {

 Stack<int, 10> s;
 s.push(10);
 int i;
 s.top(i);
 cout << i << endl;

}
