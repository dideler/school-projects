  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex7.4.array1.h
  #ifndef EX7_4_ARRAY1_H
  #define EX7_4_ARRAY1_H
  #include "ex7.4.array.h"

  namespace ARRAY_NAMESPACE {
    // helpers

    template <typename T>    
    // T is a model of Equality Comparable 
    bool operator==(const Array<T>&, const Array<T>&);

    template <typename T>  
    // T is a model of Equality Comparable 
    bool operator!=(const Array<T>&, const Array<T>&);   
  }
  #endif
