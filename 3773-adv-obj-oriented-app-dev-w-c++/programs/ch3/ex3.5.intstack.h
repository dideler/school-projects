// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex3.5.intstack.h
// Bounded stack of integers
// There are three stack operations available:
//   push() to push an integer
//   pop() to pop the top of the stack (without returning it)
//   top() to return the top of the stack without popping it.
// If any operation fails then it sets the appropriate error
//   code, which can be obtained with getError() 
//   and cleared using clearError().
// Note: this implementation does not provide an empty() operation
//   that checks whether the stack is empty

#ifndef INTSTACK_H
#define INTSTACK_H
class IntStack {
 public:
  explicit IntStack(int = 100);  // default size
  IntStack(const IntStack&);
  ~IntStack();
  IntStack& operator=(const IntStack&);
  void push(int);
  void pop();
  int top() const;

  enum ErrorState {STACK_OK, STACK_FULL, STACK_EMPTY};
  void clearError();
  ErrorState getError() const;
 private:
  int top_; // Not the element at the top, but the index of the top element.
  int* stack_;
  int size_;
  mutable ErrorState errorState_;
};
#endif
