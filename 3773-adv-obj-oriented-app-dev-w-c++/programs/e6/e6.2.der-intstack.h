
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: e6.2.der-intstack.h
  // Exercise 6.2
  // Note: In this version, copying (using a copy constructor and assignments)
  //       has become protected and therefore inaccessible to clients  
  #ifndef E6_2_DER_INTSTACK_H
  #define E6_2_DER_INTSTACK_H
  #include <stdexcept>
  using namespace std;
  #include "e6.2.intstack.h"

  class DerIntStack: protected IntStack {
  public:
    DerIntStack(int = 100);  
    ~DerIntStack();
    using IntStack::push;
    using IntStack::pop;
    bool empty() const;
    bool full() const;
  };
  #endif

