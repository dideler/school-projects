// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.1.cachedfileops.h

#ifndef EX6_1_CACHEDFILEOPS_H
#define EX6_1_CACHEDFILEOPS_H

#include "ex6.1.abstractfile.h"
#include <fstream>
#include <string>

class CachedFileOps : public AbstractFileOps // Concrete Product
{
 public:
  virtual long lines() const;
  void clearCache();
  CachedFileOps(const std::string&);
  ~CachedFileOps();
 private:
  mutable long lines_;
  mutable bool linesCached_;
  mutable std::ifstream fileVar_;
};

#endif
