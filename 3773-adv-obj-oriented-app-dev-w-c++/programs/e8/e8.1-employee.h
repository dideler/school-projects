// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1

#ifndef E8_1_EMPLOYEE_H
#define E8_1_EMPLOYEE_H

#include <string>
using std::string;

class Employee
{
 public:
  Employee(const string &name = "", double salary = 0);
  string name() const;
  double salary() const;
  int id() const;
  void setName(const string&);
  void setSalary(double);
 private:
  string name_;
  double salary_;
  int id_;
  static int currentId_;
};

#endif
