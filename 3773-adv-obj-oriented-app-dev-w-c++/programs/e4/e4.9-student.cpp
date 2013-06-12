// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: e4.9-student.cpp
// Definitions of operations from the class Student

#include "e4.9-student.h"

namespace e4_9 { // extending namespace e4_9 from header

long Student::idCounter_ = 0;

Student::Student(const string& name) : name_(name), id_(idCounter_++) { }

string Student::getName() const { return name_; }

long Student::getId() const { return id_; }

void Student::setName(const string& name) { name_ = name; }
} // namespace e4_9
