// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex3.5.intstack.cpp
// Implementation of integer stack operations

#include "ex3.5.intstack.h"
IntStack::IntStack(int size) {
  top_ = -1;
  size_ = size;
  stack_ = new int[size];
  errorState_ = STACK_EMPTY;
}

IntStack::IntStack(const IntStack& s) {
  top_ = s.top_;
  size_ = s.size_;
  stack_ = new int[size_];
  for (int i = 0; i <= top_; ++i)
    stack_[i] = s.stack_[i];
  errorState_ = s.errorState_;
}

IntStack& IntStack::operator=(const IntStack& s) {
  if (this == &s)
    return *this;
  if (size_ != s.size_) {
    delete [] stack_;
    stack_ = new int[s.size_];
  }
  top_ = s.top_;
  size_ = s.size_;
  for (int i = 0; i <= top_; ++i)
    stack_[i] = s.stack_[i];
  errorState_ = s.errorState_;
  return *this;
}

IntStack::~IntStack() {
  delete [] stack_;
}

void IntStack::push(int i) {
  if (top_ == size_ - 1) { // full
    errorState_ = STACK_FULL;
    return;
  }
  stack_[++top_] = i;
  errorState_ = STACK_OK;
}

int IntStack::top() const {
  if (top_ == -1) { // empty
    errorState_ = STACK_EMPTY;
    return 0; // must return something
  }
 
  errorState_ = STACK_OK; // WHY? Stack may be full.
  return stack_[top_];
}

// Doesn't actually pop the element, just modifies the top index.
void IntStack::pop() {
  if (top_ == -1) { // empty
    errorState_ = STACK_EMPTY;
    return;
  }
 
  errorState_ = STACK_OK;
  top_--;
}

void IntStack::clearError() {
  errorState_ = STACK_OK;
}

IntStack::ErrorState IntStack::getError() const {
  return errorState_;
}
