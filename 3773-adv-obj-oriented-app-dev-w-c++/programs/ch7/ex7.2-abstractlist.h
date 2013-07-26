// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley

#ifndef EX7_2_ABSTRACTLIST_H
#define EX7_2_ABSTRACTLIST_H  

#include "ex7.2-iterator.h"

namespace LIST_POLYMORPHIC_ITERATION
{

typedef int T;

class AbstractList
{
 public:
  AbstractList();
  virtual ~AbstractList();
  virtual void insert(const T&) = 0; // insert in front
  virtual bool remove(T&) = 0; // delete first; return true if successful
  virtual long size() const = 0;
  virtual AbstractIterator* makeIterator() const = 0; // in Java: elements()
};

} // namespace LIST_POLYMORPHIC_ITERATION

#endif
