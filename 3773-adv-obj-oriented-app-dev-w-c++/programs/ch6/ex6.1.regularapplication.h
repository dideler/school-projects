// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.1.regularapplication.h

#ifndef EX6_1_REGULARAPPLICATION_H
#define EX6_1_REGULARAPPLICATION_H

#include "ex6.1.abstractapplication.h"
#include "ex6.1.fileops.h"
#include <string>

class RegularApplication : public AbstractApplication // Concrete Factory
{
 public:
  RegularApplication(const std::string&);
  ~RegularApplication();
  virtual FileOps* factoryMethod() const;
 private:
  std::string filename_; 
};

#endif
