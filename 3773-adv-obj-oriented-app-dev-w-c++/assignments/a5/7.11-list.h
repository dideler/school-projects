/**
 * COMP 3773 - Assignment 5 - Exercise 7.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface (definitions) for the template classes List & ListIterator and
 * template struct Link.
 * 
 * The list and iterator are very basic and are loosely based on example 7.1.
 * Caution, there is no exception handling.
 * Undefined behaviour will occur if an invalid position or range is specified.
 * If you need a list for production, use or extend std::list instead.
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

template <typename T> // Note: <class T> can also be used.
class ListIterator; // Forward declaration.

template <typename T>
struct Link // A list is composed of many links (aka nodes).
{
  Link(const T &value, Link *head) : data(value), next(head) {}
  T data;
  Link *next;
};

template <typename T>
class List
{
 public:
  List() : head_(nullptr), size_(0) {}

  List(const List<T> &other) : size_(other.size_)
  {
    if (other.head_ == nullptr) // Empty list.
      head_ = nullptr;
    else
      head_ = new Link<T>(*(other.head_));
  }

  List<T> &operator=(const List<T> &other)
  {
    if (this != &other)
    {
      size_ = other.size_;
      (*head_) = (*other.head_);
    }
    return *this;
  }

  ~List() { while (size_ > 0) pop_front(); }

  // Element access (modifiers and queries):

  // Access i-th element.
  T& operator[](int position) // Note: [] is called the subscript operator.
  {
    Link<T> *temp = head_;
    while (position --> 0)
      temp = temp->next;
    return temp->data;
  }

  // Access i-th element.
  const T& operator[](int position) const
  {
    Link<T> *temp = head_;
    while (position --> 0)
      temp = temp->next;
    return temp->data;
  }

  // Access first element.
  T& front() { return head_->data; }
  
  // Access first element.
  const T& front() const { return head_->data; }

  // Access last element.
  T& back()
  {
    Link<T> *temp = head_;
    for (size_t i = 1; i < size_; ++i)
      temp = temp->next;
    return temp->data;
  }

  // Access last element.
  const T& back() const
  {
    Link<T> *temp = head_;
    for (size_t i = 1; i < size_; ++i)
      temp = temp->next;
    return temp->data;
  }
  
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
    if (size_ <= 0) return;
    Link<T> *temp = head_->next;
    delete head_;
    head_ = temp;
    --size_;
  }

  // Capacity:

  // Test whether container is empty.
  bool empty() const { return size_ == 0; }

  // Return size.
  int size() const { return size_; }

  // Iterators:

  // Return iterator to beginning.
  ListIterator<T> begin() { return ListIterator<T>(head_, *this); }

  // Return iterator to end.
  ListIterator<T> end() { return ListIterator<T>(nullptr, *this); }

 private:
  Link<T> *head_; // The first link in the list.
  size_t size_; // Number of links in the list.
};

template <typename T>
class ListIterator
{
 public:
  ListIterator(Link<T> *t, List<T> &l) : current_(t), list_(l) {}

  // Prefix (pre-increment). Advances the iterator by one position.
  ListIterator& operator++()
  {
    current_ = current_->next;
    return *this;
  }
  
  // Dereference the iterator to get the current data pointed to.
  T& operator*()
  {
    return current_->data;
  }

  // Dereference the iterator to get the current const data pointed to.
  const T& operator*() const
  {
    return current_->data;
  }

 private: 
  Link<T> *current_; // Current element.
  List<T> &list_;  // List being iterated.

  template <typename U>
  friend bool operator==(const ListIterator<U>&, const ListIterator<U>&);

  friend class List<T>;
};

// Helpers

// Postfix (post-increment). Dummy int needed to differentiate from prefix.
// Textbook says to have this as a helper because it returns a new object.
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
