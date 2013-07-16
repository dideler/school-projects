// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.1.cachedapplication.cpp
//
// Implementation for the class CachedApplication

#include "ex6.1.cachedapplication.h"
#include "ex6.1.cachedfileops.h"
#include <string>

CachedFileOps* CachedApplication::factoryMethod() const
{
  return new CachedFileOps(filename_);
}

CachedApplication::CachedApplication(const std::string& filename)
    : filename_(filename) {}

CachedApplication::~CachedApplication() {}

void CachedApplication::clearCache()
{
  CachedFileOps* cfo = factoryMethod();
  cfo->clearCache();
}

