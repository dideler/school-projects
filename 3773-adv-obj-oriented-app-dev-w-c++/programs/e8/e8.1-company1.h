  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  // file: e8.1-company1.h
#ifndef E8_1_COMPANY1_H
#define E8_1_COMPANY1_H
#include "e8.1-company2.h"
  class Company1 : public Company2 {
  public:
    Company1(int rep) throw(std::range_error);
                 // value of rep is for representation: list/vector/deque
  };
#endif

