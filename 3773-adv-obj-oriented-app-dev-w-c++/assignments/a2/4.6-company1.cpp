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
//  file: 4.6-company1.cpp  
// Implementation of class Company1
//
// Modified by Dennis Ideler for assignment 2.
#include <string>
#include <stdexcept>
#include "4.6-employee.h"
#include "4.6-company1.h"

// These constructors and assignment operator intentionally left blank.
Company1::Company1() {};
Company1::Company1(const Company1&) {};
void Company1::operator=(const Company1&) {};

// Singleton design pattern, using the static nonlocal variables idiom.
Company1& Company1::getInstance()
{
  static Company1 instance;
  return instance;
}

string Company1::name(int i) const throw(std::range_error)
{
  if (i < 0 || i >= 10) throw range_error("wrong index");
  return staff_[i].name();
}

double Company1::salary(int i) const throw(std::range_error)
{
  if (i < 0 || i >= 10) throw range_error("wrong index"); 
  return staff_[i].salary();
}

long Company1::id(int i) const throw(std::range_error)
{
  if (i < 0 || i >= 10) throw range_error("wrong index"); 
  return staff_[i].id();
}

void Company1::setName(int i, const string& n) throw(std::range_error)
{
  if (i < 0 || i >= 10) throw range_error("wrong index"); 
  staff_[i].setName(n);
}

void Company1::setSalary(int i, double d) throw(std::range_error)
{
  if (i < 0 || i >= 10) throw range_error("wrong index");
  staff_[i].setSalary(d);                   
}
