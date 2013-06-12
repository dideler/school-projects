// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ch5.studentwithaccount.h
//
// This subclass inherits from Student, so it has the same attributes,
// in addition to a balance and balance operations.

#ifndef STUDENTWITHACCOUNT_H
#define STUDENTWITHACCOUNT_H
#include "ch5.student.h"
#include <string>
class StudentWithAccount : public Student // no "extends" like Java
{
 public:
  StudentWithAccount(long, string, double = 0.0);
  double getBalance() const;
  void setBalance(double);
  void printInfo() const; // Note that it's not virtual/polymorhpic.
  void info(const Student&, const StudentWithAccount&);
 private:
  double balance_;
};
#endif
