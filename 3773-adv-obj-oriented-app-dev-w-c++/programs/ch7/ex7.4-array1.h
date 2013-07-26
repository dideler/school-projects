// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
//  Extends array namespace with extra overloaded operators (as helpers).

#ifndef EX7_4_ARRAY1_H
#define EX7_4_ARRAY1_H

#include "ex7.4-array.h"

namespace ARRAY_NAMESPACE
{

template <typename T> // T is a model of Equality Comparable 
bool operator==(const Array<T>&, const Array<T>&);

template <typename T> // T is a model of Equality Comparable 
bool operator!=(const Array<T>&, const Array<T>&);

}

#endif
