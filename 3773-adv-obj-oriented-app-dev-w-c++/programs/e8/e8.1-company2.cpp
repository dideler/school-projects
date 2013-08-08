// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1

#include "e8.1-company2.h"
#include "e8.1-collection-ifc.h"
#include "e8.1-collection-list.h"
#include "e8.1-collection-vector.h"
#include "e8.1-collection-deque.h"

Company2::Company2(int size, int rep) throw(range_error)
{
  if (size < 1 || rep < 0 || rep > 2 )
    throw range_error("Wrong parameter for Company's constructor");
  size_ = size;
  count_ = 0;
  switch (rep)
  {
    case 0:
      rep_ = new CollectionList();
      break;
    case 1:
      rep_ = new CollectionVector();
      break;  
    case 2:
      rep_ = new CollectionDeque();
      break;
  }
}

Company2::~Company2() { delete rep_; }

void Company2::hire(const string& s, double salary) throw(range_error)
{
  if (count_ == size_) throw range_error("Can't hire more employees");
  rep_->add(Employee(s, salary));
  ++count_;
}

void Company2::fire(int id) throw(range_error)
{
  if (count_ == 0) throw range_error("Can't fire employees");
  --count_;
  rep_->remove(id);
}

string Company2::name(int id) const throw(range_error)
{
  return rep_->name(id);
}

double Company2::salary(int id) const throw(range_error)
{
  return rep_->salary(id);
}

vector<int> Company2::id(const string& s) const throw(range_error)
{
  return rep_->id(s);
}

void Company2::setSalary(int id, double salary) throw(range_error)
{
  rep_->setSalary(id, salary);
}
