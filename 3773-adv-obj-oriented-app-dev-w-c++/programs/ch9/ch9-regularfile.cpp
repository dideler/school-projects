  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-regularfile.cpp
  // Example 9.3
#include "ch9-regularfile.h"
#include "ch9-visitor.h"
    RegularFile::RegularFile(const string& s) : File(s) {}
    RegularFile::~RegularFile() {}
    void RegularFile::cat() const {
      cout << contents_ << endl;
    }
    void RegularFile::insert(const string& s) {
      contents_ = contents_ + s;
   }
