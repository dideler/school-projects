// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.function.h

#ifndef EX6_2_FUNCTION_H
#define EX6_2_FUNCTION_H
#include <string>

class Function
{
 public:
  virtual void display() const = 0;
  Function(const std::string&);
  virtual ~Function();
 protected:
  std::string pol_;
};

#endif
