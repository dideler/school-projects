// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.1.regularapplication.cpp
// Implementation for the class RegularApplication

#include "ex6.1.regularapplication.h"
#include "ex6.1.fileops.h"
#include <string>

RegularApplication::RegularApplication(const std::string& filename)
    : filename_(filename) {}

RegularApplication::~RegularApplication() {}

// Returns pointer to the non-cached file operations.
FileOps* RegularApplication::factoryMethod() const
{
  return new FileOps(filename_);
}
