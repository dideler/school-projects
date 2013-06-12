  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  //////////////////////////
  // File: intstack.cpp
  // Implementation of stack operations
  #include "intstack.h"
  #include <stdexcept>
  #include <iostream>
  using namespace std;

  IntStack::IntStack(int size) {
    top_ = -1;
    size_ = size;
    stack_ = new int[size];
  }

  IntStack::~IntStack() {
    delete [] stack_;
  }

  void IntStack::push(int i) throw (logic_error) {
    if(top_ == size_ - 1)                               // full
      throw logic_error("Stack full ");
 
    stack_[++top_] = i;
  }

  int IntStack::pop() throw (logic_error) {
    if(top_ == -1)                                    // empty
      throw logic_error("Stack empty ");

    return stack_[top_--];
  }

  bool IntStack::empty() const {
	  return top_ == -1;
  }
  // end of file intstack.cpp
  /////////////////////////
