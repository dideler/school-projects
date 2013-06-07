// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// Exercise 3.8
// Sample main program
//
// Modified by Dennis Ideler for assignment 2.
#include <iostream>
using namespace std;
#include "4.6-company1.h"
#include "4.6-company2.h"

int main()
{
  try { Company1::getInstance().setName(-1, "john"); }
  catch(range_error& e) { cout << "setting name: " << e.what() << endl; }

  try
  {
    Company1::getInstance().setName(0, "john");
    Company1::getInstance().setSalary(0, 20);
    cout << "name should be john: " << Company1::getInstance().name(0) << endl;
    cout << "salary should be 20: " << Company1::getInstance().salary(0) << endl;
  }
  catch(range_error& e) { cout << e.what() << endl; }
  // These constructor calls would intentionally fail.
  //Company1 test;
  //Company1 test = Company1::getInstance();

  try { Company2::getInstance(-1); }
  catch(range_error& e) { cout << "creating 2nd company: " << e.what() << endl; }

  try
  {
    Company2::getInstance(1);
    cout << Company2::getInstance()->id(1) << endl; // employee exists at index 0
  }
  catch(range_error& e)
  {
    cout << "accessing 1-st employee: " << e.what() << endl;
  }

  try
  {
    Company2::getInstance(1);
    cout << "id = " << Company2::getInstance()->id(0) << endl;
    Company2::getInstance()->setName(0, "Mary");
    Company2::getInstance()->setSalary(0, 20000);
    cout << "name = " << Company2::getInstance()->name(0) << endl;
    cout << "salary = " << Company2::getInstance()->salary(0) << endl;
  }
  catch(range_error& e)
  {
    cout << "accessing 1-st employee " << e.what() << endl;
  }

  // Explicitly delete both instances (drawback of singleton w/ pointers).
  delete Company2::getInstance();
  delete Company2::getInstance();
}
