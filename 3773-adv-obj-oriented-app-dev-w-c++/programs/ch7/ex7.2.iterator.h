  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File ex7.2.iterator.h
// #include <stdexcept>
//#include <iostream>
// using namespace std;
#ifndef EX7_2_ITERATOR_H
#define EX7_2_ITERATOR_H
namespace LIST_POLYMORPHIC_ITERATION {
  typedef int T;

  class AbstractIterator { // abstract
  public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0; // throw(std::range_error) = 0 ;
  };
}
#endif

