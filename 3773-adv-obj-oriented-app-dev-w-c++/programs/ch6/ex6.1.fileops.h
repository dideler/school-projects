// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex6.1.fileops.h

#ifndef EX6_1_FILEOPS_H
#define EX6_1_FILEOPS_H

#include "ex6.1.abstractfile.h"
#include <fstream>
#include <string>

class FileOps : public AbstractFileOps // Concrete Product
{
 public:
  virtual long lines() const;
//virtual void clearCache();
  FileOps(const std::string&);
  ~FileOps();
 private:
  mutable std::ifstream fileVar_;
};

#endif
