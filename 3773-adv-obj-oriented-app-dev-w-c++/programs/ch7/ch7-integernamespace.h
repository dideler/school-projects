// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Section 7.3, page 281
//
// Interface for a namespace with a class showing overloaded operators.

#ifndef INTEGERNAMESPACE_H
#define INTEGERNAMESPACE_H

#include <iostream>
using namespace std;

namespace IntegerNamespace
{

class Integer
{
  friend istream& operator>>(istream&, Integer&);
 public:
  explicit Integer(int i = 0);
  int get() const;
  Integer& operator++(); 
  Integer& operator+=(const Integer&); 
  Integer& operator+=(int); 
 private: 
  int value_;
};

// Helpers
Integer operator+(const Integer&, const Integer&);
Integer operator+(int, const Integer&);
Integer operator+(const Integer&, int);
Integer operator++(Integer&, int);

istream& operator>>(istream&, Integer&);
ostream& operator<<(ostream&, const Integer&);

} // namespace IntegerNamespace

#endif
