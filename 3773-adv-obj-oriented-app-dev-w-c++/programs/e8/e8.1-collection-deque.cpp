// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1
//
// Implementation for the deque implementation of CollectionIfc.

#include "e8.1-collection-deque.h"
#include "e8.1-employee.h"

// Get employee name.
string CollectionDeque::name(int id) const throw(range_error)
{
  for (CollectionDeque::const_iterator i = head_.begin(); i != head_.end(); ++i)
    if (i->id() == id)
      return i->name();
  throw range_error("Can't get a name of non-existing employee"); 
}

// Hire new employee.
void CollectionDeque::add(const Employee& e) { head_.push_back(e); }

// Terminate an employee.
void CollectionDeque::remove(int id) throw(range_error)
{
  for (CollectionDeque::iterator i = head_.begin(); i != head_.end(); ++i)
  {
    if (i->id() == id)
    {
      head_.erase(i);
      return;
    }
  }
  throw range_error("Can't remove non-existing employee");
}

// Get employee salary.
double CollectionDeque::salary(int id) const throw(range_error)
{
  for (CollectionDeque::const_iterator i = head_.begin(); i != head_.end(); ++i)
    if (i->id() == id)
      return i->salary();
  throw range_error("Can't get salary of non-existing employee"); 
}

// Get all employee IDs.
// FIXME: doesn't throw exception even though it was designed to
vector<int> CollectionDeque::id(const string& name) const throw(range_error)
{
  vector<int> v;
  for (CollectionDeque::const_iterator i = head_.begin(); i != head_.end(); ++i)
    if (i->name() == name)
      v.push_back(i->id());
  return v;
}

// Set employee salary.
void CollectionDeque::setSalary(int id, double salary) throw(range_error)
{
  for (CollectionDeque::iterator i = head_.begin(); i != head_.end(); ++i)
  {
    if (i->id() == id)
    {
      i->setSalary(salary);
      return;
    }
  }
  throw range_error("Can't set salary of non-existing employee"); 
}

CollectionDeque::~CollectionDeque() {}
