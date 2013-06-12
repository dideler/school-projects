  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex7.1.list.cpp
  // Implementation of class List for Exercise 7-1
  #include "ex7.1.list.h"
  typedef  int T;
  namespace LIST_ITERATION_NAMESPACE {

    struct Link_ {  // struct, because Link is private
      T value_;
      Link_* next_;
      Link_(const T&, Link_*); // link with the next element
    };

    Link_::Link_(const T& t, Link_* h) : value_(t), next_(h) {}

    List::List() : head_(0), size_(0) {}

    List::~List() {
      T junk;
      while(remove(junk))
        ;
    }

    int List::size() const {
      return size_;
    }

    void List::insert(const T& t) {
      Link_* temp = new Link_(t, head_);
      head_ = temp;
      ++size_;
    }

    bool List::remove(T& t) {
      if(size_ == 0)
        return false;
      --size_;
      Link_* temp = head_;
      t = head_->value_; 
      head_ = temp->next_;
      delete temp;
      return true;
    }
 
    List::ListIterator::ListIterator(Link_* t) : current_(t) {}

    T& List::ListIterator::operator*() {
      return current_->value_;
    }
    const T& List::ListIterator::operator*() const {
      return current_->value_;
    }   
    List::ListIterator List::begin()  const {
      return List::ListIterator(head_);
    }

    List::ListIterator List::end() const {
      return ListIterator();
    }

    List::ListIterator& List::ListIterator::operator++() { // prefix
      current_ = current_->next_;
      return *this;
    }
 
    List::ListIterator operator++(List::ListIterator& i, int) { // postfix
      List::ListIterator temp(i);
      ++i;
      return temp;
    }

    bool operator==(const List::ListIterator& i, const List::ListIterator& j) {
      return i.current_ == j.current_;
    }

    bool operator!=(const List::ListIterator& i, const List::ListIterator& j) {
      return !(i == j);
    }

  }
