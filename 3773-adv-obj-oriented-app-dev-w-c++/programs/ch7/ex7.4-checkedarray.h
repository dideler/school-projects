// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// Another extension of array namespace.
// CheckedArray is a specific implementation of Array with exception handling.

#ifndef EX7_4_CHECKED_ARRAYS_H
#define EX7_4_CHECKED_ARRAYS_H

#include "ex7.4-array.h"
#include <stdexcept>
using std::out_of_range;

namespace ARRAY_NAMESPACE
{

template <typename T> // T is a model of Default Constructible 
class CheckedArray : public Array<T>
{
 public:
  CheckedArray(size_t = 100);
  CheckedArray(const CheckedArray<T>&);
  CheckedArray<T>& operator=(const CheckedArray<T>&) throw (out_of_range);
  virtual ~CheckedArray();
  virtual const T& operator[](int) const throw(out_of_range);
  virtual T& operator[](int) throw(out_of_range);
};

// Helpers

template <typename T> // T is a model of Equality Comparable 
bool operator==(const CheckedArray<T>&, const CheckedArray<T>&)
    throw (out_of_range);

template <typename T> // T is a model of Equality Comparable 
bool operator!=(const CheckedArray<T>&, const CheckedArray<T>&)
    throw (out_of_range);

} // namespace ARRAY_NAMESPACE

#endif
