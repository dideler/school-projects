// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.1.bankaccount.cpp
//
// Example 5.1
// Implementation of class BankAccount

#include "ex5.1.bankaccount.h"
#include "ex5.1.student.h"
#include "ex5.1.accountforstudent.h"
#include "ex5.1.bank.h"
#include <string>
#include <iostream>
using namespace std;

// This overloaded operator uses the parent class overloaded operator.
BankAccount& BankAccount::operator=(const BankAccount& b)
{
  if (this == &b)
    return *this;
  AccountForStudent::operator=(b); // assign base part

  // copy bank
  delete bank_;
  bank_ = new Bank(b.bank_->getName());
  return *this;
}

BankAccount::BankAccount(long number, const string& name, double balance,
                         Bank* b)
    : AccountForStudent(number, name, balance), bank_(b) {}

BankAccount::~BankAccount() { delete bank_; }

void BankAccount::printInfo() const
{
  AccountForStudent::printInfo();
  cout << "Bank: " << bank_->getName() << endl;
}
