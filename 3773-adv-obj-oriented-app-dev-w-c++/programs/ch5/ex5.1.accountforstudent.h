// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.1.accountforstudent.h
//
// Example 5.1
// Interface for class AccountForStudent

#ifndef ACCOUNTFORSTUDENT_H
#define ACCOUNTFORSTUDENT_H
#include <string>
using namespace std;
class Student;
class AccountForStudent
{
 public:
  AccountForStudent(long number, const string& name, double balance);
  virtual ~AccountForStudent(); // doesn't need to be virtual
  AccountForStudent& operator=(const AccountForStudent&);
  void printInfo() const;
 protected:
  Student* stud_;
  double balance_;
};
#endif
