  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-company2.cpp
  //  the version with dequeus does not compile using gnu c++, it works fine with visual C++
  // Therefore deques are commented here  
#include "e8.1-company2.h"
#include "e8.1-collection-ifc.h"
#include "e8.1-collection-list.h"
#include "e8.1-collection-vector.h"
// #include "e8.1-collection-deque.h"

    void Company2::hire(const string& s, double salary) throw(std::range_error) {
                //hire new employee     
      if(count_ == size_)
        throw std::range_error("can't hire more employees");
      rep_->add(Employee(s, salary));
      ++count_;
    }
    void Company2::fire(int id) throw(std::range_error) {
      if(count_ == 0)
        throw std::range_error("can't fire employees"); 
      --count_;
      rep_->remove(id);
    }
    string Company2::name(int id) const throw(std::range_error) { // name of employee     
      return rep_->name(id);
    }
    double Company2::salary(int id) const throw(std::range_error) { // salary given id
      return rep_->salary(id);
    }
    vector<int> Company2::id(const string& s) const throw(std::range_error) { // id of employee
      return rep_->id(s);
    }
    void Company2::setSalary(int id, double salary) throw(std::range_error) { // set salary 
      rep_->setSalary(id, salary);
    }
    Company2::Company2(int size, int i) throw(std::range_error) {
            // value of determines the representation: list/vector/deque
       if(size < 0 || i < 0 || i > 1 /* 2 */ )  // 2 is for deques
         throw std::range_error("wrong parameter of the Compnay's constructor");
       size_ = size;
       count_ = 0;
       switch(i) {
       case 0: rep_ = new CollectionList();
               break;
       case 1: rep_ = new CollectionVector();
               break;  
//     case 2: rep_ = new CollectionDeque();
//             break;  
       }
     } 
     Company2::~Company2() {
       delete rep_;
     }

