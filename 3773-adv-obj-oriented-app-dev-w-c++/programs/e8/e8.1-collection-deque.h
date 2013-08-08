// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1
//
// Interface for the deque (short for dequeue) implementation of CollectionIfc.

#ifndef E8_1_COLLECTION_DEQUE_H
#define E8_1_COLLECTION_DEQUE_H

#include <deque>
using std::deque;

#include "e8.1-collection-ifc.h"

class Employee;

class CollectionDeque : public CollectionIfc
{
 public:
  virtual void add(const Employee&);
  virtual void remove(int id) throw(range_error);
  virtual string name(int id) const throw(range_error);
  virtual double salary(int id) const throw(range_error);
  virtual vector<int> id(const string&) const throw(range_error);
  virtual void setSalary(int id, double) throw(range_error);
  virtual ~CollectionDeque();
 private:
  typedef deque<Employee>::iterator iterator;
  typedef deque<Employee>::const_iterator const_iterator;
  deque<Employee> head_; 
};

#endif
