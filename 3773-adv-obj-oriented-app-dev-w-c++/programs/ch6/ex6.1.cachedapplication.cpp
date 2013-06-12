
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.1.cachedapplication.cpp
  // Implementation for the class CachedApplication

  #include "ex6.1.cachedapplication.h"
  #include "ex6.1.cachedfileops.h"
  #include <string>
  #include <iostream>
  CachedFileOps* CachedApplication::factoryMethod() const {
    return new CachedFileOps(filename_);
  }

  CachedApplication::CachedApplication(const string& filename): filename_(filename) {}

  CachedApplication::~CachedApplication() {}
  void CachedApplication::clearCache() { 
     AbstractFileOps* afo = factoryMethod();
     if(CachedFileOps* cs = dynamic_cast<CachedFileOps*>(afo))
        cs->clearCache();
     else cerr << "non caching application tried to cache " << endl;
 }

