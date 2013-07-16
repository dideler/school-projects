// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: e6.2.intstack.cpp
// 
// Implementation of class IntStack

#include "e6.2.intstack.h"

IntStack::IntStack(int size)
{
  top_ = -1;
  size_ = size;
  stack_ = new int[size];
}

IntStack::IntStack(const IntStack& s)
{
  top_ = s.top_;
  size_ = s.size_;
  stack_ = new int[size_];
  for (int i = 0; i <= top_; i++)
    stack_[i] = s.stack_[i];
}

IntStack& IntStack::operator=(const IntStack& s)
{
  if (this == &s)
    return *this;

  if (size_ != s.size_)
  {
    delete [] stack_;
    stack_ = new int[s.size_];
  }

  top_ = s.top_;
  size_ = s.size_;
  for (int i = 0; i <= top_; i++)
    stack_[i] = s.stack_[i];
  return *this;
}

IntStack::~IntStack() { delete [] stack_; }

void IntStack::push(int i) throw(logic_error)
{
  if (top_ == size_ - 1) throw logic_error("Stack full ");
  stack_[++top_] = i;
}

int IntStack::pop() throw(logic_error)
{
  if (top_ == -1) throw logic_error("Stack empty ");
  return stack_[top_--];
}
