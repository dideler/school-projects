  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex3.1.student.cpp
  // Definitions of operations from the class Student
  // (placed outside of the class)
  #include "ex3.1.student.h"

  //constructor definition
  Student::Student(long number) { 
    number_ = number;
  }

  // operation definition
  void Student::modify(long number) {
    number_ = number;
  }

  long Student::get() const {
    return number_;
  }

