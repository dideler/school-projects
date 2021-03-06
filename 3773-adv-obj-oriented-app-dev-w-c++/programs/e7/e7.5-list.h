// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Exercise 7.5
// The code for ex7.1 has been modified to add a link from ListIterator to List.

#ifndef E7_5_LIST_H
#define E7_5_LIST_H

#include <stdexcept>
using std::domain_error;

namespace LIST_ITERATION_NAMESPACE
{

typedef int T;
struct Link_;  // forward declaration

class List
{
 public:
  List();
  virtual ~List();
  void insert(const T&); // insert in front
  void removeFirst(T&) throw(domain_error); // delete first; throw if fail
  int size() const; // size of the list

  class ListIterator // nested class
  {
    friend bool operator==(const ListIterator&, const ListIterator&);
    friend class List;

   public:
    T& operator*() throw(domain_error);
    const T& operator*() const throw(domain_error);
    ListIterator& operator++() throw(domain_error);
    ListIterator(Link_*, List&);
    void insertAfter(const T&) throw(domain_error); // insert after iterator
    void insertBefore(const T&) throw(domain_error); // insert before iterator    
    void remove(T&) throw(domain_error); // remove element iterator points to

   private: 
    Link_* current_;
    List& myList_;  // list being iterated
  };

  // Give friends access to privates.
  friend void ListIterator::insertAfter(const T&) throw(domain_error);
  friend void ListIterator::insertBefore(const T&) throw(domain_error);
  friend void ListIterator::remove(T&) throw(domain_error);
  ListIterator begin();
  ListIterator end();

 private:
  List(const List&);
  List& operator=(const List&);
  Link_* head_;
  int size_;
}; // List

// Declarations of helpers
List::ListIterator operator++(List::ListIterator&, int) throw(domain_error); // postfix
bool operator==(const List::ListIterator&, const List::ListIterator&);
bool operator!=(const List::ListIterator&, const List::ListIterator&); 

} // namespace LIST_ITERATION_NAMESPACE

#endif
