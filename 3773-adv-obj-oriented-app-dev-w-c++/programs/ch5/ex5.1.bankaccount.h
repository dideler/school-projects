// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.1.bankaccount.h
//
// Example 5.1
// Interface for class BankAccount 

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "ex5.1.accountforstudent.h"
#include <string>
class Bank;
class BankAccount : public AccountForStudent
{
 public:
  BankAccount(long number, const string& name, double balance, Bank*);
  virtual ~BankAccount();
  BankAccount& operator=(const BankAccount&);
  void printInfo() const;
 protected:
  Bank* bank_;
};
#endif
