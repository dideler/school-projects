  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-collection-vector.cpp
  // Implementation for the vector implementation of CollectionIfc
#include <string>
#include <stdexcept>
#include "e8.1-collection-vector.h"
#include "e8.1-employee.h"

     string CollectionVector::name(int id) const throw(std::range_error) { // name of employee
        for(CollectionVector::const_iterator i = head_.begin(); i != head_.end(); ++i)
         if(i->id() == id)
           return i->name();
       throw std::range_error("can't get a name of non-existing employee"); 
     }
     void CollectionVector::add(const Employee& e) { //hire new employee     
       head_.push_back(e);   
     }
     void CollectionVector::remove(int id) throw(std::range_error) {
       for(CollectionVector::iterator i = head_.begin(); i != head_.end(); ++i) 
         if(i->id() == id) {
           head_.erase(i);
           return;
       }
       throw std::range_error("can't remove non-existing employee");
     }
     double CollectionVector::salary(int id) const throw(std::range_error) { // salary given id
       for(CollectionVector::const_iterator i = head_.begin(); i != head_.end(); ++i)
         if(i->id() == id)
           return i->salary();
       throw std::range_error("can't get a salary of non-existing employee"); 
     }
     vector<int> CollectionVector::id(const string& name) const throw(std::range_error) { 
               // ids of all employees
        vector<int> v;
        for(CollectionVector::const_iterator i = head_.begin(); i != head_.end(); ++i)
          if(i->name() == name)  
            v.push_back(i->id());
         return v;
     }
     void CollectionVector::setSalary(int id, double salary) throw(std::range_error) { 
           // set salary given id
        for(CollectionVector::iterator i = head_.begin(); i != head_.end(); ++i)
           if(i->id() == id) {
              i->setSalary(salary);
              return;
           }
        throw std::range_error("can't get a salary of non-existing employee"); 
     }
     CollectionVector::~CollectionVector() { }

