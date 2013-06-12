  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-collection-deque.h
  // Interface for the deque implementation of CollectionIfc
  //  the version with dequeus does not compile using gnu c++, it works fine with visual C++
  // Therefore deques are commented here
#ifndef E8_1_COLLECTION_DEQUE_H
#define E8_1_COLLECTION_DEQUE_H 
#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
// class Employee;
#include "e8.1-collection-ifc.h"
#include "e8.1-employee.h"
  class CollectionDeque: public CollectionIfc  {
  public:
    virtual void add(const Employee&); //hire new employee     
    virtual void remove(int id) throw(std::range_error);
    virtual string name(int id) const throw(std::range_error); // name of employee     
    virtual double salary(int id) const throw(std::range_error); // salary given id
    virtual vector<int> id(const string&) const throw(std::range_error); // ids of all employees
    virtual void setSalary(int id, double) throw(std::range_error); // set salary given id
    virtual ~CollectionDeque();
  private:
    typedef deque<Employee>::iterator iterator;
    typedef deque<Employee>::const_iterator const_iterator;
    deque<Employee> head_; 
  };
#endif

