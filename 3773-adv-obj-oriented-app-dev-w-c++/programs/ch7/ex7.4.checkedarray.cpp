  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex7.4.checkedarray.cpp
  #include "ex7.4.checkedarray.h"

  namespace ARRAY_NAMESPACE {

  template <typename T>
  CheckedArray<T>::CheckedArray(size_t size) : Array<T>(size) { }

  template <typename T>
  CheckedArray<T>::CheckedArray(const CheckedArray<T>& ar) : Array<T>(ar) {}

  template <typename T>
  CheckedArray<T>& CheckedArray<T>::operator=(const CheckedArray<T>& ar) 
        throw (std::std::out_of_range) {
   if(this == &ar)
       return *this;
    if(size_ != ar.size())
       throw std::out_of_range("wrong sizes in operator=");
    Array<T>::operator=(ar); 
    return *this;
  }

  template <typename T>
  CheckedArray<T>::~CheckedArray() { }

  template <typename T>
  T& CheckedArray<T>::operator[](int i) throw(std::out_of_range) {
    if(i < 0 || i >= size_)
      throw out_of_range("wrong range in []");
    return array_[i];
  }

  template <typename T>
  const T&CheckedArray<T>::operator[](int i) const throw(std::out_of_range)  {
    if(i < 0 || i >= size_)
      throw out_of_range("wrong range in []");
    return array_[i];
  }

  // helper
  template <typename T>
  bool operator==(const CheckedArray<T>& ar1, const CheckedArray<T>& ar2) 
          throw (std::out_of_range) {
    if(ar1.size() != ar2.size())
      throw std::out_of_range("wrong sizes in ==");
    return Array<T>::operator==(ar1, ar2);
  }

  // helper
  template <typename T>
  bool operator!=(const CheckedArray<T>& ar1, const CheckedArray<T>& ar2) 
       throw(std::out_of_range) {
    return !(ar1 == ar2);
  }

  // end of namespace

  }
