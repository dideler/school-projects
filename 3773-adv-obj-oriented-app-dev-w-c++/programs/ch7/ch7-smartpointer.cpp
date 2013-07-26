  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
#include "ch7.smartpointer.h"

  template<typename Body>
  Handle<Body>::Handle(Body* b) : bridge_(b) { 
    counter_ = new int(1);
  }

  template<typename Body>
  Handle<Body>::Handle(const Handle<Body>& h) : bridge_(h.bridge_) {
    counter_ = h.counter_;
    (*counter_)++;
  }

  template<typename Body>
  Handle<Body>::~Handle<Body>() {
    if(--counter_ == 0) {
      delete counter_;
      delete bridge_;
    }
  }

  template<typename Body>
  Handle<Body>& Handle<Body>::operator=(const Handle<Body>& rhs)  {
    if(this == &rhs || bridge_ == rhs.bridge_)
      return *this;

    if(--counter_ == 0) { // left-hand side has no references
      delete counter_;
      delete bridge_;
    }

    bridge_ = rhs.bridge_;
    counter_ = rhs.counter_;
    (*counter_)++;
    return *this;
  }

  template<typename Body>
  Body* Handle<Body>::operator->() {
    return bridge_;
  }
 
  template<typename Body>
  Body& Handle<Body>::operator*() {
    return *bridge_;
  }

