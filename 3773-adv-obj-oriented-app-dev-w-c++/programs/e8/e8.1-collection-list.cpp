  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-collection-list.cpp
  // Implementation for the list implementation of CollectionIfc
#include <string>
#include <stdexcept>
#include "e8.1-collection-list.h"
#include "e8.1-employee.h"
#include <iostream>

     string CollectionList::name(int id) const throw(std::range_error) { // name of employee
        for(CollectionList::const_iterator i = head_.begin(); i != head_.end(); ++i)
         if(i->id() == id)
           return i->name();
       throw std::range_error("can't get a name of non-existing employee"); 
     }
     void CollectionList::add(const Employee& e) { //hire new employee     
       head_.push_front(e);   
     }
     void CollectionList::remove(int id) throw(std::range_error) {
       for(CollectionList::iterator i = head_.begin(); i != head_.end(); ++i) 
         if(i->id() == id) {
           head_.erase(i);
           return;
       }
       throw std::range_error("can't remove non-existing employee");
     }
     double CollectionList::salary(int id) const throw(std::range_error) { // salary given id
       for(CollectionList::const_iterator i = head_.begin(); i != head_.end(); ++i)
         if(i->id() == id)
           return i->salary();
       throw std::range_error("can't get a salary of non-existing employee"); 
     }
     vector<int> CollectionList::id(const string& name) const throw(std::range_error) { 
               // ids of all employees
        vector<int> v;
        for(CollectionList::const_iterator i = head_.begin(); i != head_.end(); ++i)
          if(i->name() == name)  
            v.push_back(i->id());
         return v;
     }
     void CollectionList::setSalary(int id, double salary) throw(std::range_error) { 
           // set salary given id
        for(CollectionList::iterator i = head_.begin(); i != head_.end(); ++i)
           if(i->id() == id) {
              i->setSalary(salary);
              return;
           }
        throw std::range_error("can't get a salary of non-existing employee"); 
     }
     CollectionList::~CollectionList() { }

