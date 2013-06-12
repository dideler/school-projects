// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex3.2.student-d.cpp
// Simple tester for the Student class

#include "ex3.2.student.h"

int main() {
  Student s(100, "ex3.2.student.data");
  cout << "showing once" << endl;
  s.show();
  cout << endl << "showing twice" << endl;
  s.show();
}

