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
  Link<T> *temp = new Link(element, head_);
  head_ = temp;
  ++size_;
}

template <typename T>
void List<T>::pop_front()
{
  Link<T> *temp = head_;
  head_ = temp->next;
  delete temp;
  --size_;
}

template <typename T>
bool List<T>::empty() const { return size_ == 0; }

template <typename T>
int List<T>::size() const { return size_; }

template <typename T>
List<T>::Link<T>::Link(const T &t, Link<T> *l) : value(t), next(l) {}

template <typename T>
List<T>::ListIterator<T>::ListIterator(Link<T> *t, List<T> &l)
    : current_(t),
      list_(l) {}

template <typename T>
T& List<T>::ListIterator<T>::operator*() { return current_->value; }

template <typename T>
const T& List<T>::ListIterator<T>::operator*() const { return current_->value; }

template <typename T>
typename List<T>::ListIterator<T> List<T>::begin()
{
  return List<T>::ListIterator(head_, *this);
}

template <typename T>
typename List<T>::ListIterator<T> List<T>::end()
{
  return ListIterator(nullptr, *this); // FIXME why does it not complain? List<T>::
}

template <typename T>
typename List<T>::ListIterator<T>& List<T>::ListIterator::operator++() // Prefix.
{
  current_ = current_->next;
  return *this;
}

template <typename T>
typename List<T>::ListIterator<T> operator++(typename List<T>::ListIterator<T> &iter,
                                          int) // Dummy int indicates postfix.
{
  // Note: If you were to make this operation a class member instead of a helper,
  // then you would have to remove typename & the iter parameter, and write...
  //   List<T>::ListIterator temp(*this); // or temp = *this; if you overload =.
  //   ++(*this);
  typename List<T>::ListIterator<T> temp(iter);
  ++iter;
  return temp;
}

template <typename U> // TODO verify typename U works. can also try ==<T>(...)
bool operator==(const typename List<U>::ListIterator<U> &a,
                const typename List<U>::ListIterator<U> &b)
{
  return a.current_ == b.current_;
}

template <typename T>
bool operator!=(const typename List<T>::ListIterator<T> &a,
                const typename List<T>::ListIterator<T> &b)
{
  return !(a == b);
}

} // namespace mylist
