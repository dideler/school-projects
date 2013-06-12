  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Example 9.3
  // File: ch9-file.cpp
#include "ch9-file.h"
    File::~File() {}
    string File::name() const {
      return name_;
   }
   File::File(const string& s) : name_(s) {}

