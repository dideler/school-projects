
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.1.regularapplication.cpp
  // Implementation for the class RegularApplication

  #include "ex6.1.regularapplication.h"
  #include "ex6.1.fileops.h"
  #include <string>
  #include <iostream>
  FileOps* RegularApplication::factoryMethod() const {
    return new FileOps(filename_);
  }
  RegularApplication::RegularApplication(const string& filename) :filename_(filename) {}
  RegularApplication::~RegularApplication() {}

