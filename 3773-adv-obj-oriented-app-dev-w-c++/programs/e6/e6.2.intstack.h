
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: e6.2.intstack.h
  // Exercise 6.2
  // Interface for class IntStack 
  #ifndef E6_2_INTSTACK_H
  #define E6_2_INTSTACK_H
  #include <stdexcept>
  using namespace std;
  class IntStack {
  public:
    IntStack(int = 100);  // default size
    IntStack(const IntStack&);
    virtual ~IntStack();
    IntStack& operator=(const IntStack&);
    void push(int) throw(logic_error);
    int pop() throw(logic_error);
  protected:
    int top_;
    int* stack_;
    int size_;
  };
  #endif



