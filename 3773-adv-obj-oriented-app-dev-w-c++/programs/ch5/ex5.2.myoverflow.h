// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.2.myoverflow.h
//
// Example 5.2
// Interface for class My_overflow_error

#ifndef MYOVERFLOWERROR_H
#define MYOVERFLOWERROR_H
#include <stdexcept>
#include <string>
using namespace std;

class My_overflow_error : public overflow_error
{
 public:
  explicit My_overflow_error(const string&, int, int);
  int getArg1() const;
  int getArg2() const;
 private:
  int x_;
  int y_;
}; 

#endif
