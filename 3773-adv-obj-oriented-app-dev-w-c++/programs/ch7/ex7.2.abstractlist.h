  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  //File: ex7.2.abstractlist.h
#include "ex7.2.iterator.h"
#ifndef EX7_2_ABSTRACTLIST_H
#define EX7_2_ABSTRACTLIST_H  
 namespace LIST_POLYMORPHIC_ITERATION {
typedef int T;
  class AbstractList {  // abstract
  public:
    AbstractList();
    virtual ~AbstractList();
    virtual void insert(const T&) = 0; // insert in front
    virtual bool remove(T&) = 0;    // delete first; return true if successful
    virtual long size() const = 0;
    virtual LIST_POLYMORPHIC_ITERATION::AbstractIterator* makeIterator() const = 0; // in Java: elements()
  };
}
#endif

