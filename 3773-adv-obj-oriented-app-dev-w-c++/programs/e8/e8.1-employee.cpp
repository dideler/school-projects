  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-employee.cpp
#include <string>
#include "e8.1-employee.h"
    int  Employee::currentId_ = 1000;
  
    Employee::Employee(const string& n, double s) : name_(n), salary_(s) {
       id_ = currentId_++;
    }
    string Employee::name() const{
      return name_;
    }
    double Employee::salary() const{
      return salary_;
    }
    int Employee::id() const{
      return id_;
    }
    void Employee::setName(const string& n) {
      name_ = n;
    }
    void Employee::setSalary(double d) {
      salary_ = d;
    }

