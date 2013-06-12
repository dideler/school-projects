// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ch5.studentwithaccount.cpp

#include <iostream>
using namespace std;
#include "ch5.studentwithaccount.h"
#include "ch5.student.h"

// Note that some of the parameters are passed to the base class' constructor.
StudentWithAccount::StudentWithAccount(long number, string name, double balance)
    : Student(number, name), balance_(balance) {}

double StudentWithAccount::getBalance() const { return balance_; }

void StudentWithAccount::setBalance(double balance) { balance_ = balance; }

// This method is not virtual.
void StudentWithAccount::printInfo() const
{
  Student::printInfo(); // call to a base class member
  cout << "Balance: " << balance_ << endl;
}

// This method exists to show that you have to access the inherited attributes
// through the child class, not the parent class.
void StudentWithAccount::info(const Student& s, const StudentWithAccount& swa)
{
  //cout << s.number_ << endl; // can't access through Student
  cout << swa.number_ << endl; // can access through StudentWithAccount
}
