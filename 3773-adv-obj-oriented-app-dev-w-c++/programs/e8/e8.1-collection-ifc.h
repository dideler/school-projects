  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-collection-ifc.h
  // There may be many employees with the same name, but ID is a unique key
#ifndef E8_1_COLLECTION_IFC_H
#define E8_1_COLLECTION_IFC_H 
#include <string>
#include <stdexcept>
#include <vector>
#include "e8.1-employee.h"
  class CollectionIfc {
  public:
    virtual void add(const Employee&)  = 0; //hire new employee     
    virtual void remove(int id) throw(std::range_error) = 0;
    virtual string name(int id) const throw(std::range_error) = 0; // name of employee     
    virtual double salary(int id) const throw(std::range_error) = 0; // salary given id
    virtual vector<int> id(const string&) const throw(std::range_error) = 0; // ids of all employees
    virtual void setSalary(int id, double) throw(std::range_error) = 0; // set salary given id
    virtual ~CollectionIfc();
  };
#endif

