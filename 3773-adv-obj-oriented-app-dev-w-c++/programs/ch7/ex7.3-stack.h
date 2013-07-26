// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley

#ifndef EX7_3_STACK_H
#define EX7_3_STACK_H

#include <cstddef> // One of many libraries that defines size_t.

template <typename T, size_t SIZE>
class Stack // template class
{
 public:
  Stack(); 
  ~Stack();
  void push(const T& new_item);
  void pop();
  void top(T& item) const;
  bool is_empty() const;
  bool is_full() const;
 private:
  int top_;
  T stack_[SIZE];
};

#endif
