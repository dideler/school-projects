  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-collection-deque.cpp
  // Implementation for the list implementation of CollectionIfc
  //  the version with dequeus does not compile using gnu c++, it works fine with visual C++
  // Therefore deques are commented here
#include <string>
#include <stdexcept>
#include "e8.1-collection-deque.h"
#include "e8.1-employee.h"

     string CollectionDeque::name(int id) const throw(std::range_error) { // name of employee
        for(CollectionDeque::const_iterator i = head_.begin(); i != head_.end(); ++i)
         if(i->id() == id)
           return i->name();
       throw std::range_error("can't get a name of non-existing employee"); 
     }
     void CollectionDeque::add(const Employee& e) { //hire new employee     
       head_.push_front(e);   
     }
     void CollectionDeque::remove(int id) throw(std::range_error) {
       for(CollectionDeque::iterator i = head_.begin(); i != head_.end(); ++i) 
         if(i->id() == id) {
           head_.erase(i);
           return;
       }
       throw std::range_error("can't remove non-existing employee");
     }
     double CollectionDeque::salary(int id) const throw(std::range_error) { // salary given id
       for(CollectionDeque::const_iterator i = head_.begin(); i != head_.end(); ++i)
         if(i->id() == id)
           return i->salary();
       throw std::range_error("can't get a salary of non-existing employee"); 
     }
     vector<int> CollectionDeque::id(const string& name) const throw(std::range_error) { 
               // ids of all employees
        vector<int> v;
        for(CollectionDeque::const_iterator i = head_.begin(); i != head_.end(); ++i)
          if(i->name() == name)  
            v.push_back(i->id());
         return v;
     }
     void CollectionDeque::setSalary(int id, double salary) throw(std::range_error) { 
           // set salary given id
        for(CollectionDeque::iterator i = head_.begin(); i != head_.end(); ++i)
           if(i->id() == id) {
              i->setSalary(salary);
              return;
           }
        throw std::range_error("can't get a salary of non-existing employee"); 
     }
     CollectionDeque::~CollectionDeque() { }

