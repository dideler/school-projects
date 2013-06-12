  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-regularfile.h  
  // Example 9.3
#ifndef REGULARFILE_H
#define REGULARFILE_H
#include <string>
#include "ch9-file.h"
class Visitor;
  class RegularFile : public File {
  public:
    virtual void accept(Visitor& v) { v.visit(this); }
    RegularFile(const string&);
    virtual ~RegularFile();
    void cat() const;  // catenate file
    void insert(const string&); // insert a string into a file
  private:
    string contents_;
  };
#endif

