  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-company2.h
  // There may be many employees with the same name, but ID is a unique key
#ifndef E8_1_COMPANY2_H
#define E8_1_COMPANY2_H
#include <string>
#include <stdexcept>
#include <vector>
  class CollectionIfc;
  class Company2 {
  public:
    void hire(const string&, double) throw(std::range_error); //hire new employee     
    void fire(int id) throw(std::range_error);
    string name(int id) const throw(std::range_error); // name of employee     
    double salary(int id) const throw(std::range_error); // salary given id
    vector<int> id(const string&) const throw(std::range_error); // ids of all employees
    void setSalary(int id, double) throw(std::range_error); // set salary given id
    Company2(int size, int rep) throw(std::range_error);
                 // value of rep is for representation: list/vector/deque
    virtual ~Company2();
  private:
    CollectionIfc* rep_;  // abstract collection
    int size_;  // maximum size
    int count_; // current number of employees
  };
#endif

