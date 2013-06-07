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
// The interface for Company1 consists of 3 queries that get an attribute of the i-th
// employee or throw an exception if i is incorrect, and two setters, respectively for
// the name and the salary
// file: 4.6-company1.h
//
// Modified by Dennis Ideler for assignment 2.
#ifndef E3_8_COMPANY1_H
#define E3_8_COMPANY1_H
#include "4.6-employee.h" // Cannot use forward declaration.
#include <string>
#include <stdexcept>
class Company1
{
 public:
  static Company1& getInstance();
  string name(int) const throw(std::range_error);
  double salary(int) const throw(std::range_error);
  long id(int) const throw(std::range_error);
  void setName(int, const string&)  throw(std::range_error);
  void setSalary(int, double) throw(std::range_error);
 private:
  Company1();
  Company1(const Company1&);
  void operator=(const Company1&);
  Employee staff_[10];
};
#endif
