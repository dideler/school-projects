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
template <typename T>
class ListIterator;

template <typename T>
struct Link
{
  Link(const T &t, Link *l) : value(t), next(l) {}
  T value;
  Link *next;
};

template <typename T> // Note: `class T` can also be used.
class List
{
 public:
  List() : head_(nullptr), size_(0) {}
  //List(const List<T> &other);
  //List<T>& operator=(const List<T> &other);
  ~List() { while (size_ > 0) pop_front(); }

  // Element access:

  // Overloaded subscript operator [] returns the i-th element in the container.
  // Caution, undefined behaviour if an invalid position or range is specified.
  T& operator[](int position)
  {
    Link<T> *temp = head_;
    while (position --> 0)
      temp = temp->next;
    return temp->value;
  }

  const T& operator[](int position) const
  {
    Link<T> *temp = head_;
    while (position --> 0)
      temp = temp->next;
    return temp->value;
  }

  T& front() { return head_->value; }
  
  const T& front() const { return head_->value; }

  //T& back(); // TODO try list.end() - 1;
  //const T& back() const;
  
  // Modifiers:

  // Insert an element from the front.
  void push_front(const T &element)
  {
    Link<T> *temp = new Link<T>(element, head_);
    head_ = temp;
    ++size_;
  }

  // Remove an element from the front.
  void pop_front()
  {
    Link<T> *temp = head_;
    head_ = temp->next;
    delete temp;
    --size_;
  }

  // Capacity:

  bool empty() const
  {
    return size_ == 0;
  }

  int size() const
  {
    return size_;
  }

  // Iterators:

  ListIterator<T> begin()
  {
    return ListIterator<T>(head_, *this);
  }

  ListIterator<T> end()
  {
    return ListIterator<T>(nullptr, *this);
  }

 private:
  Link<T> *head_; // The first link in the list.
  size_t size_;
};

template <typename T>
class ListIterator
{
 public:
  ListIterator(Link<T> *t, List<T> &l) : current_(t), list_(l) {}

  ListIterator& operator++() // Prefix.
  {
    current_ = current_->next;
    return *this;
  }
 
//  ListIterator& operator++(int) // Postfix.
//  {
//    ListIterator temp(*this);
//    ++(*this);
//    return temp;
//  }

  // Element access
  
  // Dereference the iterator to get the current value pointed to.
  T& operator*()
  {
    return current_->value;
  }

  // Dereference the iterator to get the current const value pointed to.
  const T& operator*() const
  {
    return current_->value;
  }

 private: 
  Link<T> *current_; // Current element.
  List<T> &list_;  // List being iterated.

  template <typename U>
  friend bool operator==(const ListIterator<U>&, const ListIterator<U>&);
  friend class List<T>;
};

// Helpers

// Postfix, post-increments the iterator. Dummy int needed to differentiate.
// Preference in the book is to have this as a helper because it returns a new
// object. My preference is to have it as a member, but I still kept it as
// a helper to demonstrate how to befriend it (see ListIterator class).
template <typename T>
ListIterator<T> operator++(ListIterator<T> &iter, int)
{
  ListIterator<T> temp(iter);
  ++iter;
  return temp;
}

template <typename T>
bool operator==(const ListIterator<T> &a, const ListIterator<T> &b)
{
  return a.current_ == b.current_;
}

template <typename T>
bool operator!=(const ListIterator<T> &a, const ListIterator<T> &b)
{
  return !(a == b);
}

} // namespace mylist

#endif
