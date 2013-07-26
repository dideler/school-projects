// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Sample main program for example 7-3.
// Example of a class template.

#include "ex7.3-stack.cpp"
#include <iostream>
using namespace std;

int main()
{
 Stack<int, 10> s;
 s.push(10);
 int i;
 s.top(i); // this is stupid, should return IMO.
 cout << i << endl;
}
