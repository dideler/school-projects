// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex3.2.student.cpp
// Implementation of the Student's methods

#include "ex3.2.student.h"

Student::Student(long number, const string& filename)
  : number_(number), inFile_(filename.c_str()), validFile_(inFile_) {}

long Student::number() const { return number_; }

void Student::show() {
  if (!validFile_) {
    cout << "Can't open the input file\n";
    return;
  } 
  inFile_.seekg(0); // rewind to get ready for the next show()

  string line;
  while (getline(inFile_, line)) // inFile_ >> word
    cout << line << endl;
  inFile_.clear(); // clear the error state
}

Student::~Student() { inFile_.close(); }
