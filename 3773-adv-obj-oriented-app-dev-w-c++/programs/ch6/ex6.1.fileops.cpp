// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex6.1.fileops.cpp
// Implementation for the class FileOps

#include "ex6.1.fileops.h"
#include <fstream>

// void FileOps::clearCache() {}

long FileOps::lines() const
{
  long lines = 0;
  char c;
  while (fileVar_.get(c))
    if (c == '\n') ++lines;
  fileVar_.clear();
  fileVar_.seekg(0);
  return lines;
}

FileOps::FileOps(const std::string& filename) : fileVar_(filename.c_str()) {}

FileOps::~FileOps() {}
