// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1
//
// There may be many employees with the same name, but ID is a unique key.

#ifndef E8_1_COLLECTION_IFC_H
#define E8_1_COLLECTION_IFC_H 

#include <string>
#include <stdexcept>
#include <vector>
using std::string;
using std::range_error;
using std::vector;

#include "e8.1-employee.h"

class CollectionIfc
{
 public:
  virtual void add(const Employee&) = 0; // Hire new employee.
  virtual void remove(int id) throw(range_error) = 0; // Terminate employee.
  virtual string name(int id) const throw(range_error) = 0; // Employee name.
  virtual double salary(int id) const throw(range_error) = 0; // Employee salary.
  virtual vector<int> id(const string&) const throw(range_error) = 0; // All employee IDs.
  virtual void setSalary(int id, double) throw(range_error) = 0; // Set employee salary.
  virtual ~CollectionIfc();
};

#endif
