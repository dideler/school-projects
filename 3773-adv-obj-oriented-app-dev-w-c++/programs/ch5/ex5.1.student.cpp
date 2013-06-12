// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex5.1.student.cpp
//
// Example 5.1
// Interface for class Student

#include "ex5.1.student.h"
#include <iostream>
using namespace std;

Student::Student(long number, string name) : number_(number), name_(name) {}

long Student::getNumber() const { return number_; }

string Student::getName() const { return name_; }

void Student::printInfo() const
{
  cout << "Student number: " << number_
       << "\nName: " << name_ << endl;
}
