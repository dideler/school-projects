  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-employee.h
#ifndef E8_1_EMPLOYEE_H
#define E8_1_EMPLOYEE_H
#include <string>
  class Employee {
  public:
    explicit Employee(const string& = "", double = 0);
    string name() const;
    double salary() const;
    int id() const;
    void setName(const string&);
    void setSalary(double);
  private:
    string name_;
    double salary_;
    int id_;
    static int currentId_;
  };
#endif

