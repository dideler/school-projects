  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-collection-list.h
  // Interface for the list implementation of CollectionIfc
#ifndef E8_1_COLLECTION_VECTOR_H
#define E8_1_COLLECTION_VECTOR_H 
#include <string>
#include <stdexcept>
#include <vector>
class Employee;
#include "e8.1-collection-ifc.h"
  class CollectionVector: public CollectionIfc  {
  public:
    virtual void add(const Employee&); //hire new employee     
    virtual void remove(int id) throw(std::range_error);
    virtual string name(int id) const throw(std::range_error); // name of employee     
    virtual double salary(int id) const throw(std::range_error); // salary given id
    virtual vector<int> id(const string&) const throw(std::range_error); // ids of all employees
    virtual void setSalary(int id, double) throw(std::range_error); // set salary given id
    virtual ~CollectionVector();
  private:
    typedef vector<Employee>::iterator iterator;
    typedef vector<Employee>::const_iterator const_iterator;
    vector<Employee> head_; 
  };
#endif
