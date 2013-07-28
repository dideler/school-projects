/**
 * COMP 3773 - Assignment 5 - Exercise 7.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface (definition) for the template class List.
 * A simple list, based on the one from exercise 7.5 / example 7.1. 
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> // For size_t.

namespace mylist
{

// Forward declarations (can be avoided if member classes made public).
//struct Link;
//class ListIterator;

template <typename T> // Note: `class T` can also be used.
class List
{
  //template <typename T>
  struct Link
  {
    Link(const T&, Link*);
    T value;
    Link *next;
  };

  //template <typename T>
  class ListIterator
  {
   public:
    ListIterator(Link*, List&);
    ListIterator& operator++(); // Prefix operator; modifier thus member.

    // Element access
    T& operator*();
    const T& operator*() const;

   private: 
    Link *current_; // Current element.
    List &list_;  // List being iterated.

    //friend bool operator==(const ListIterator&, const ListIterator&);
    friend class List;
  };
 public:
  List();
  //List(const List<T> &other); // TODO keep?
  //List<T>& operator=(const List<T> &other); // TODO keep?
  ~List();

  // Element access
  //List<T>& operator[](int);
  //const List<T>& operator[](int) const;
  //T& front(); // TODO
  //const T& front() const;
  //T& back(); // TODO try list.end() - 1;
  //const T& back() const;
  
  // Modifiers
  void insert(const T &element);
  void pop_front();

  // Capacity
  bool empty() const;
  int size() const;

  // Iterators
  ListIterator begin();
  ListIterator end();

  //typedef T element_type; // Used to be useful for retrieving type of a
                            // template's argument. Can use `auto` since C++11.

 private:
  Link *head_;
  size_t size_;

};
/* 
// Declarations of helpers // TODO verify typename needed here, shouldn't be
template <typename T>
typename List<T>::ListIterator operator++(typename List<T>::ListIterator&, int); // Postfix. // TODO try without dummy int param

template <typename T>
bool operator==(const typename List<T>::ListIterator&,
                const typename List<T>::ListIterator&);

template <typename T>
bool operator!=(const typename List<T>::ListIterator&,
                const typename List<T>::ListIterator&); 
*/
} // namespace mylist

#endif
