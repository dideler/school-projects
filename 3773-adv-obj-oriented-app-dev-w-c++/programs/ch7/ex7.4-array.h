// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley

#ifndef EX7_4_ARRAY_H
#define EX7_4_ARRAY_H

#include <stdexcept>
//typedef int size_t; TODO remove

namespace ARRAY_NAMESPACE
{

template <typename T> // T is a model of Default Constructible
class Array // template class
{
 public:
  Array(size_t = 100);
  Array(const Array<T>&);
  Array<T>& operator=(const Array<T>&);
  virtual ~Array();
  virtual const T& operator[](int) const;
  virtual T& operator[](int);
  int size() const;
  typedef T element_type;
 protected:
  size_t size_;
  T* array_;
};

} // namespace ARRAY_NAMESPACE

#endif
