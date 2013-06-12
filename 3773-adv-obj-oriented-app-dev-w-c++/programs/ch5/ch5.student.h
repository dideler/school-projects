// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ch5.student.h

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class Student
{
 public:
  Student(long = 0, string = "");
  long getNumber() const;
  string getName() const;
  void printInfo() const;
 protected:
  long number_;
  string name_;
};
#endif
