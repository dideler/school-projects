// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.1.accountforstudent.cpp
//
// Example 5.1
// Implementation of class AccountForStudent

#include <iostream>
#include <string>
#include "ex5.1.accountforstudent.h"
#include "ex5.1.student.h"

AccountForStudent::AccountForStudent(long number, const string& name,
                                     double balance)
{ // using an initializer list is superior
  stud_ = new Student(number, name);
  balance_ = balance;
}

AccountForStudent::~AccountForStudent() { delete stud_; }

AccountForStudent& AccountForStudent::operator=(const AccountForStudent& as)
{
  if (this == &as)
    return *this;
  delete stud_;
  stud_ = new Student(as.stud_->getNumber(), as.stud_->getName());
  balance_ = as.balance_;
  return *this;
}

void AccountForStudent::printInfo() const
{
  stud_->printInfo();
  cout << "Balance: " << balance_ << endl;
}
