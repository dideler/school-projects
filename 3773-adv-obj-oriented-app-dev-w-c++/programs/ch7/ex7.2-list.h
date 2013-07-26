// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Concrete aggregate

#ifndef EX7_2_LIST_H
#define EX7_2_LIST_H 

#include "ex7.2-abstractlist.h"
#include "ex7.2-iterator.h" // abstract iterator

namespace LIST_POLYMORPHIC_ITERATION
{

struct Link_; // declaration

class List : public AbstractList
{
 public:
  List();
  virtual ~List();
  virtual void insert(const T&);
  virtual bool remove(T&); 
  virtual long size() const;
  virtual AbstractIterator* makeIterator() const;

 private:
  List(const List&);
  List& operator=(const List&);
  Link_* head_;
  int size_;

  class ListIterator : public AbstractIterator
  {
   public:
    virtual bool hasNext() const;
    virtual T next(); // throw(std::range_error);
    ListIterator(Link_* = 0);
   private:
    Link_* current_;
  };
};

} // namespace LIST_POLYMORPHIC_ITERATION

#endif
