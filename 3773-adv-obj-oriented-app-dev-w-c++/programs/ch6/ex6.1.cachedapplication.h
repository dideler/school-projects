// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.1.cachedapplication.h

#ifndef EX6_1_CACHEDAPPLICATION_H
#define EX6_1_CACHEDAPPLICATION_H

#include "ex6.1.abstractapplication.h"
#include "ex6.1.cachedfileops.h"
#include <string>

class CachedApplication : public AbstractApplication // Concrete Factory
{
 public:
  CachedApplication(const std::string&);
  ~CachedApplication();
  virtual CachedFileOps* factoryMethod() const;
  void clearCache();
 private:
  std::string filename_;
};

#endif
