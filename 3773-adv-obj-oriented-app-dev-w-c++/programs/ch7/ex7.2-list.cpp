// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Implementation of class List

#include "ex7.2-list.h"

namespace LIST_POLYMORPHIC_ITERATION
{

struct Link_
{
  T value_;
  Link_* next_;
  Link_(const T&, Link_*); // link with the next element
};

Link_::Link_(const T& t, Link_* h) : value_(t), next_(h) {}

List::List() : head_(0), size_(0) {}

List::~List()
{
  T aux;
  while (remove(aux)) {}
}

long List::size() const { return size_; }

void List::insert(const T& t)
{
  Link_* temp = new Link_(t, head_);
  head_ = temp;
  ++size_;
}

bool List::remove(T& t)
{
  if (size_ == 0) return false;
  --size_;
  Link_* temp = head_;
  head_ = temp->next_;
  delete temp;
  return true;
}

List::ListIterator::ListIterator(Link_* t) : current_(t) {}

AbstractIterator* List::makeIterator() const
{
  return new List::ListIterator(head_);
}

bool List::ListIterator::hasNext() const { return current_ != 0; }

T List::ListIterator::next() // throw(std::range_error) {
{
  if (current_ == 0)
  return 0; // throw std::range_error();
  int v =  current_->value_;
  current_ = current_->next_;
  return v;
}

} // namespace LIST_POLYMORPHIC_ITERATION
