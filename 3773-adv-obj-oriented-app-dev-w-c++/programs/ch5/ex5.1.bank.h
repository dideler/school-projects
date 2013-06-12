// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.1.bank.h
//
// Example 5.1
// Interface for class Bank

#ifndef BANK_H
#define BANK_H 
#include <string> 
using namespace std;
class Bank
{
 public:
  Bank(const string&);
  string getName() const;
 private:
  string name_;
};
#endif
