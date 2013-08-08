// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1
//
// There may be many employees with the same name, but ID is a unique key.

#ifndef E8_1_COMPANY2_H
#define E8_1_COMPANY2_H

#include <string>
#include <stdexcept>
#include <vector>
using std::string;
using std::range_error;
using std::vector;

class CollectionIfc;

class Company2
{
 public:
  Company2(int size, int rep) throw(range_error);
  virtual ~Company2();
  void hire(const string&, double) throw(range_error);
  void fire(int id) throw(range_error);
  string name(int id) const throw(range_error);
  double salary(int id) const throw(range_error);
  vector<int> id(const string&) const throw(range_error);
  void setSalary(int id, double) throw(range_error);
private:
  CollectionIfc* rep_;  // Abstract collection.
  int size_;  // Maximum size.
  int count_; // Current number of employees.
};

#endif
