  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Section 7.3, page 282
  // implementation of a namespace with a class showing overloaded operators 
  // File: ch7.integernamespace.cpp
  #include "ch7.integernamespace.h"
  namespace IntegerNamespace {  // definitions

  // members
  Integer::Integer(int i) : value_(i) {}

  int Integer::get() const {
    return value_;
  }

  Integer& Integer::operator+=(const Integer& i) {
    value_ += i.value_;
    return *this;
  }

  Integer& Integer::operator+=(int v) {
    value_ += v;
    return *this;
  }
   
  Integer& Integer::operator++() {  // prefix; member of Integer
    ++value_;
    return *this;
  }

  // helpers
  Integer operator+(int v, const Integer& i) {
    Integer j = i;
    j += v;  // call: Integer::operator+=(int)
    return j;
  }

  Integer operator+(const Integer& i, int v) {
    Integer j = i;
    j += v;  // call: Integer::operator+=(int)
    return j;
  }

  Integer operator+(const Integer& i1, const Integer& i2) {
    Integer j = i1;
    j += i2;  // call: Integer::operator+=(const Integer&)
    return j;
  }

  Integer operator++(Integer& x, int) { //postfix; helper
    Integer local(x);  // save x
    ++x;        // update x using member
    return local;
  }

  istream& operator>>(istream& is, Integer& i) {
    is >> i.value_;   //friends are allowed
    return is;
  }

  ostream& operator<<(ostream& os, const Integer& i) {
    os << i.get();
    return os;
  }

  }
