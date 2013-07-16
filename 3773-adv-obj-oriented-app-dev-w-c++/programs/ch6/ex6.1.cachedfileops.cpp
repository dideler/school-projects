// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.1.cachedfileops.cpp
//
// Implementation for the class CachedFileOps

#include "ex6.1.cachedfileops.h"
#include <iostream>
#include <fstream>
#include <string>

CachedFileOps::CachedFileOps(const std::string& filename)
    : lines_(0), linesCached_(false), fileVar_(filename.c_str()) {}

CachedFileOps::~CachedFileOps() {}

long CachedFileOps::lines() const
{
  if (linesCached_) return lines_;

  lines_ = 0;
  linesCached_ = true;

  char c;
  while (fileVar_.get(c))
    if (c == '\n') ++lines_;
  
  fileVar_.clear();
  fileVar_.seekg(0);

  return lines_;
}

void CachedFileOps::clearCache()
{
  linesCached_ = false;
  std::cout << "cached file ops: cleared cache " << std::endl;
}
