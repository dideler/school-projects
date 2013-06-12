// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.2.myunderflow.h
//
// Example 5.2
// Interface for class My_underflow_error  

#ifndef MYUNDERFLOWERROR_H
#define MYUNDERFLOWERROR_H
#include <stdexcept> // for underflow_error
#include <string>
using namespace std;

class My_underflow_error : public underflow_error
{
 public:
  explicit My_underflow_error(const string&, int, int);
  int getArg1() const;
  int getArg2() const;
 private:
  int x_;
  int y_;
};

#endif
