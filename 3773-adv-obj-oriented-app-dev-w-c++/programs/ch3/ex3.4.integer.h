// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex3.4.integer.h
// A wrapper class for integer values
#ifndef INTEGER_H
#define INTEGER_H
class Integer {
 public:
  Integer(int = 0);
  int get() const;
  Integer& set(int);
  Integer& add(const Integer&);
 private:
  int value_;
};
#endif

