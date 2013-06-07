// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// Exercise 3.8
// Write a class Employee that represents an employee with three attributes:
// name, salary, and id. Id numbers for new employees are assigned values
// 1000, 1001, etc. Carefully design the interface for this class.
// Then, write the following classes:
// - Company1, which represents a company that can hire up to 10 employees,
// these employees are stored in an array
// - Company2, which represents a company that can hire up to n employees, where
// the value of n is determined in the constructor; these employees are stored in an array
// Finally, write a main program to both classes.
// The interface for Employee consists of 3 queries that get an attribute of the
// employee, and two setters, respectively for the name and the salary   
// file: 4.6-employee.cpp
// Implementation of class Employee
//
// Modified by Dennis Ideler for assignment 2.
#include <string>
#include "4.6-employee.h"

long Employee::currentId_ = 1000;

Employee::Employee(const string& n, double s) : name_(n), salary_(s) {
    id_ = currentId_++;
}

string Employee::name() const{
  return name_;
}

double Employee::salary() const{
  return salary_;
}

long Employee::id() const{
  return id_;
}

void Employee::setName(const string& n) {
  name_ = n;
}

void Employee::setSalary(double d) {
  salary_ = d;
}
