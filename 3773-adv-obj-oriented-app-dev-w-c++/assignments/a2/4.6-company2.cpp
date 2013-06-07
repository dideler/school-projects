// Tomasz Muldner, September 2002
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// Exercise 3.8
// file: 4.6-company2.cpp
// Implementation of class Company2
//
// Modified by Dennis Ideler for assignment 2.
#include <string>
#include <stdexcept>
#include "4.6-employee.h"
#include "4.6-company2.h"

Company2* Company2::instance1_ = nullptr;
Company2* Company2::instance2_ = nullptr;

Company2* Company2::getInstance() throw(std::logic_error)
{
  if (instance2_ != nullptr) return instance2_; // instance2_ preferred.
  if (instance1_ != nullptr) return instance1_;
  throw logic_error("No instances exist; cannot create one without size given");
}

Company2* Company2::getInstance(int i) throw(std::range_error)
{
  if (instance1_ == nullptr)
  {
    instance1_ = new Company2(i);
    return instance1_;
  }
  if (instance2_ == nullptr)
  {
    instance2_ = new Company2(i);
    return instance2_;
  }
  return instance2_; // Why instance2_ and not instance1_? No reason.
}

// Creates a dynamic array of employees or throws a range error if wrong index.
Company2::Company2(int i) throw(std::range_error)
{
  if (i <= 0) throw range_error("wrong index");  
  current_ = i;
  staff_ = new Employee[i];
}

Company2::Company2(const Company2&) {};

void Company2::operator=(const Company2&) {};

Company2::~Company2()
{
  delete [] staff_;
  if (instance2_ != nullptr) instance2_ = nullptr;
  else if (instance1_ != nullptr) instance1_ = nullptr;
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

//char Company2::count = 0;
