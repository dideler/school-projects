// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1
//
// Interface for the vector implementation of CollectionIfc.

#ifndef E8_1_COLLECTION_VECTOR_H
#define E8_1_COLLECTION_VECTOR_H 

#include "e8.1-collection-ifc.h"

class Employee;

class CollectionVector : public CollectionIfc
{
 public:
  virtual void add(const Employee&);
  virtual void remove(int id) throw(range_error);
  virtual string name(int id) const throw(range_error);
  virtual double salary(int id) const throw(range_error);
  virtual vector<int> id(const string&) const throw(range_error);
  virtual void setSalary(int id, double) throw(range_error);
  virtual ~CollectionVector();
 private:
  typedef vector<Employee>::iterator iterator;
  typedef vector<Employee>::const_iterator const_iterator;
  vector<Employee> head_; 
};

#endif
