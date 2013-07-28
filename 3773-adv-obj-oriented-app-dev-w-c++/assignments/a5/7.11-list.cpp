/**
 * COMP 3773 - Assignment 5 - Exercise 7.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation (definition) of template class List.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#include "7.11-list.h"

namespace mylist
{

template <typename T>
List<T>::List() : head_(nullptr), size_(0) {}

//template <typename T>
//List<T>::List(const List<T> &other) {} // TODO

//template <typename T>
//List<T>& List<T>::operator=(const List<T> &other) {} // TODO

template <typename T>
List<T>::~List() { while (size_ > 0) pop_front(); }

//template <typename T>
//const T& List<T>::operator[](int) const {}

//template <typename T>
//T& List<T>::operator[](int) {}

template <typename T>
void List<T>::insert(const T &element)
{
  Link *temp = new Link(element, head_);
  head_ = temp;
  ++size_;
}

template <typename T>
void List<T>::pop_front()
{
  Link *temp = head_;
  head_ = temp->next_;
  delete temp;
  --size_;
}

template <typename T>
bool List<T>::empty() const { return size_ == 0; }

template <typename T>
int List<T>::size() const { return size_; }

template <typename T>
List<T>::Link::Link(const T &t, Link *l) : value(t), next(l) {}

template <typename T>
List<T>::ListIterator::ListIterator(Link *t, List &l)
    : current_(t),
      list_(l) {}

template <typename T>
T& List<T>::ListIterator::operator*() { return current_-> value_; }

template <typename T>
const T& List<T>::ListIterator::operator*() const { return current_-> value_; }

template <typename T>
typename List<T>::ListIterator List<T>::begin()
{
  return List<T>::ListIterator(head_, *this);
}

template <typename T>
typename List<T>::ListIterator List<T>::end()
{
  return ListIterator(nullptr, *this); // FIXME why does it not complain? List<T>::
}

template <typename T>
typename List<T>::ListIterator& List<T>::ListIterator::operator++() // Prefix.
{
  current_ = current_->next_;
  return *this;
}
/*
// TODO try removing dummy int paramater
template <typename T>
List<T>::ListIterator operator++(List<T>::ListIterator& iter, int) // Postfix.
{
  List::ListIterator temp(iter);
  ++iter;
  return temp;
}

template <typename T>
bool operator==(typename const List<T>::ListIterator &a, typename const List<T>::ListIterator &b)
{
  return a.current_ == b.current_;
}

template <typename T>
bool operator!=(const List<T>::ListIterator &a, const List<T>::ListIterator &b)
{
  return !(a == b);
}
*/
} // namespace mylist
