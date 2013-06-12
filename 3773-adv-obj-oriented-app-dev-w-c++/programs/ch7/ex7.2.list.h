  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File ex7.2.list.h
  #include "ex7.2.abstractlist.h"
  #include "ex7.2.iterator.h"
#ifndef EX7_2_LIST_H
#define EX7_2_LIST_H 
namespace LIST_POLYMORPHIC_ITERATION {
  // ConcreteAggregate
	
  struct Link_;   // declaration

  class List : public AbstractList {  // implement 
  public:
    List();
    virtual ~List();

    virtual void insert(const T&);
    virtual bool remove(T&); 
    virtual long size() const;
    virtual LIST_POLYMORPHIC_ITERATION::AbstractIterator* makeIterator() const; 

  private:

      class ListIterator : public AbstractIterator { // implements 
      public:
        virtual bool hasNext() const;
        virtual T next(); // throw(std::range_error);
        ListIterator(Link_* = 0);
     private:
       Link_* current_;
	 };

     List(const List&);
     List& operator=(const List&);
     Link_* head_;
     int size_;
    };
}
#endif

