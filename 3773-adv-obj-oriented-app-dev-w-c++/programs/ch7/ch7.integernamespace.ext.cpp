  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Section 7.3, page 282
  // File ch7.integernamespace.ext.cpp
#include "ch7.integernamespace.ext.h"
  namespace IntegerNamespace {
    bool operator==(const Integer& i1, const Integer& i2) {
      return i1.get() == i2.get();
    }
    bool operator!=(const Integer& i1, const Integer& i2) {
      return !(i1 == i2);
    }
  }

