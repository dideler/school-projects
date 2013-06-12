  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-specialfile.h
  // Example 9.3
#ifndef SPECIALFILE_H
#define SPECIALFILE_H
#include "ch9-file.h"
#include <string>
class Visitor;
  class SpecialFile : public File {
  public:
    virtual void accept(Visitor& v) { v.visit(this); }
    SpecialFile(const string&);
    virtual ~SpecialFile();
  };
#endif

