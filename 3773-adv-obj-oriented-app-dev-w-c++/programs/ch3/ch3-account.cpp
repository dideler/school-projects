// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ch3-account.cpp 
// Implementation of class operations
#include "ch3-account.h"
#include "ex3.1.student.h"
AccountForStudent::AccountForStudent(long number, double balance) {
  stud_ = new Student(number);
  balance_ = balance;
}

AccountForStudent::AccountForStudent(const AccountForStudent &from) {
  stud_ = new Student(from.stud_->get());
  balance_ = from.balance_;
}
AccountForStudent::~AccountForStudent() {
  delete stud_;
}

double AccountForStudent::balance() const {
  return balance_;
}

long AccountForStudent::number() const {
  return stud_->get();
}
