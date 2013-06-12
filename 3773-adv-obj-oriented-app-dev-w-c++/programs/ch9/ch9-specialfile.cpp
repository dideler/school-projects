  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-specialfile.cpp
  // Example 9.3
#include "ch9-specialfile.h"
#include "ch9-visitor.h"
    SpecialFile::SpecialFile(const string& s) : File(s) {}
    SpecialFile::~SpecialFile() {}
