  // Version I
  // File: intstack.h
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Interface for the integer bounded stack, with exception handling
  // Available operations: push(), pop(), empty()
  // This implementation does not include: top()
  // Stacks cannot be copied
  #ifndef INTSTACK_H
  #define INTSTACK_H

  // include files
  #include <stdexcept>
  #include <iostream>
  using namespace std;

  class IntStack {
  public:
    IntStack(int = 100);                   // default size
    ~IntStack();
    void push(int) throw(logic_error);
    int pop() throw(logic_error);
    bool empty() const;
  private:
    IntStack(const IntStack&);
    IntStack& operator=(const IntStack&);

    int top_;
    int* stack_;
    int size_;
  };
  #endif
  // end of file: intstack.h
  //////////////////////////

