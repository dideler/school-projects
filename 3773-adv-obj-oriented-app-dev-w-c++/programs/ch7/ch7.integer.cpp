  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Section 7.3, page 286    
#include "ch7.integer.h"

  Integer::Integer(int i, int low, int high) throw(std::range_error) {
    rangeCheck();
  }
  
  Integer::operator int() const {
    return value_;
  }
  
  void Integer::rangeCheck() throw(std::range_error) {
     if(value_ < low_ || value_ > high_) 
        throw std::range_error("beyond range");
  }
  
  Integer operator+(const Integer& i, const Integer& j) throw(std::range_error) {
      if(i.low_ != j.low_ || i.high_ != j.high_)
        throw std::range_error("incompatible ranges");
  
      int value = i.value_ + j.value_;
      if(value < i.low_ || value > i.high_) 
        throw std::range_error("beyond range");
      return Integer(value);
  }
