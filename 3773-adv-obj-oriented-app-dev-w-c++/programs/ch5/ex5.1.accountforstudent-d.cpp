// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley

#include <iostream>
using namespace std;
#include "ex5.1.student.h"
#include "ex5.1.bank.h"
#include "ex5.1.accountforstudent.h"
#include "ex5.1.bankaccount.h"

int main()
{
  BankAccount studentaccount(100, "John", 12, new Bank("royal")); 
  studentaccount.printInfo();  
}
