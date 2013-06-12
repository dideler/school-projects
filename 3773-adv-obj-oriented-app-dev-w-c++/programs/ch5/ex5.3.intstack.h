// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.3.intstack.h
//
// Example 5.3
// Interface for class IntStack 

#ifndef INTSTACK_H
#define INTSTACK_H
#include <stdexcept>
using namespace std;

class IntStack
{
 public:
  IntStack(int = 100);  // default size
  IntStack(const IntStack&);
  ~IntStack();
  IntStack& operator=(const IntStack&);
  void push(int) throw(logic_error);
  int pop() throw(logic_error);
 private:
  int top_; // index of top element
  int* stack_;
  int size_;
};
#endif
