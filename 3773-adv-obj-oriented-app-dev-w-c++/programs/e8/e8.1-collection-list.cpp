// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1
//
// Implementation for the list implementation of CollectionIfc.

#include <iostream>
#include <stdexcept>
#include <string>

#include "e8.1-collection-list.h"
#include "e8.1-employee.h"

string CollectionList::name(int id) const throw(range_error)
{
  for (CollectionList::const_iterator i = head_.begin(); i != head_.end(); ++i)
    if (i->id() == id)
      return i->name();
  throw range_error("Can't get name of non-existing employee");
}

void CollectionList::add(const Employee& e) { head_.push_back(e); }

void CollectionList::remove(int id) throw(range_error)
{
  for (CollectionList::iterator i = head_.begin(); i != head_.end(); ++i) 
    if (i->id() == id)
    {
      head_.erase(i);
      return;
    }
  throw range_error("Can't remove non-existing employee");
}

double CollectionList::salary(int id) const throw(range_error)
{
  for (CollectionList::const_iterator i = head_.begin(); i != head_.end(); ++i)
    if (i->id() == id)
      return i->salary();
  throw range_error("Can't get a salary of non-existing employee"); 
}

// FIXME: doesn't throw exception
vector<int> CollectionList::id(const string& name) const throw(range_error)
{
  vector<int> v;
  for (CollectionList::const_iterator i = head_.begin(); i != head_.end(); ++i)
    if (i->name() == name)  
      v.push_back(i->id());
  return v;
}

void CollectionList::setSalary(int id, double salary) throw(range_error)
{
  for (CollectionList::iterator i = head_.begin(); i != head_.end(); ++i)
    if (i->id() == id)
    {
      i->setSalary(salary);
      return;
    }
  throw range_error("Can't get a salary of non-existing employee");
}

CollectionList::~CollectionList() {}
