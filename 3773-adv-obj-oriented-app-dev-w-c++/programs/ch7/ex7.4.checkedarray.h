  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex7.4.checkedarray.h
  #ifndef EX7_4_CHECKED_ARRAYS_H
  #define EX7_4_CHECKED_ARRAYS_H
  #include <stdexcept>
  #include "ex7.4.array.h"
  namespace ARRAY_NAMESPACE {

    template <typename T> 
    class CheckedArray : public Array<T> {  
    // T is a model of Default Constructible 
    public:
      CheckedArray(size_t = 100);
      CheckedArray(const CheckedArray<T>&);
      CheckedArray<T>& operator=(const CheckedArray<T>&) throw (std::out_of_range);
      virtual ~CheckedArray();
      virtual const T& operator[](int) const throw(std::out_of_range);
      virtual T& operator[](int) throw(std::out_of_range);
    };

  // helpers

  template <typename T>  
  // T is a model of Equality Comparable 
  bool operator==(const CheckedArray<T>&, const CheckedArray<T>&) throw (std::out_of_range);

  template <typename T>
  // T is a model of Equality Comparable 
  bool operator!=(const CheckedArray<T>&, const CheckedArray<T>&) throw (std::out_of_range);

  // end of namespace
  }
  #endif

