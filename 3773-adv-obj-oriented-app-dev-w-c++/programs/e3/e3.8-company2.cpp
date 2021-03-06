// Tomasz Muldner, September 2002
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// Exercise 3.8
// file: e3.8-company2.cpp
// Implementation of class Company2
#include <string>
#include <stdexcept>
#include "e3.8-employee.h"
#include "e3.8-company2.h"

// Creates a dynamic array of employees or throws a range error if wrong index.
Company2::Company2(int i) throw(std::range_error)
{
  if (i <= 0) throw range_error("wrong index");  
  current_ = i;
  staff_ = new Employee[i];
}

Company2::~Company2()
{
  delete [] staff_;
}

// Luckily we have vectors so we don't have to always code like this!
string Company2::name(int i) const throw(std::range_error)
{
  if (i < 0 || i >= current_) throw range_error("wrong index");
  return staff_[i].name();
}

double Company2::salary(int i) const throw(std::range_error)
{
  if (i < 0 || i >= current_) throw range_error("wrong index"); 
  return staff_[i].salary();
}

long Company2::id(int i) const throw(std::range_error)
{
  if (i < 0 || i >= current_) throw range_error("wrong index"); 
  return staff_[i].id();
}

void Company2::setName(int i, const string& n)  throw(std::range_error)
{
  if (i < 0 || i >= current_) throw range_error("wrong index"); 
  staff_[i].setName(n);
}

void Company2::setSalary(int i, double d) throw(std::range_error)
{
  if (i < 0 || i >= current_) throw range_error("wrong index");
  staff_[i].setSalary(d);                   
}
