// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex3.1.student-d.cpp
//  test program for the class Student
#include "ex3.1.student.h"
#include <iostream>
using namespace std;

int main() {
  Student s(100);
  cout << s.get() << endl;
  s.modify(20);
  cout << s.get() << endl;
}
