// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ch6.stack.h

#ifndef CH6_STACK_H
#define CH6_STACK_H

class Stack : private Dequeue // Doesn't inherit the interface
{
 public:
  Stack(int size = 10);
  ~Stack();
  void push(int);
  int pop();
  bool full() const;
};

#endif
