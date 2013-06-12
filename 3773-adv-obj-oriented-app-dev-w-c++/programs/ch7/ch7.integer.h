  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Section 7.3, page 286
  // File: ch7.integer.h
#ifndef CH7_INTEGER_H
#define CH7_INTEGER_H
#include <stdexcept>

 class Integer {
  public:
    explicit Integer(int = 0, int low = 0, int high = 100) 
        throw(std::range_error);
    friend Integer operator+(const Integer&, const Integer&) 
       throw(std::range_error);
    operator int() const;
    // ...
  private:
    void rangeCheck() throw(std::range_error);
    int value_;
    int low_;   // low bound of the range
    int high_;  // high bound
  };
#endif

