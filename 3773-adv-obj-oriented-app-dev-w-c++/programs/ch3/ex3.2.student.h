// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex3.2.student.h
// Class Student, with three attributes: number, file, and a boolean flag
// Both attributes are set by the constructor and cannot be changed
// The file attribute is a nested object

#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class Student { 
 public:
  Student(long, const string&);  // constructor
  long number() const;           // shows the number    
  void show();                   // shows the file
  ~Student();                    // destructor
 private:
  long number_;                  // student number
  ifstream inFile_;              // file variable
  bool validFile_;               // has file been successfully opened
};

#endif
