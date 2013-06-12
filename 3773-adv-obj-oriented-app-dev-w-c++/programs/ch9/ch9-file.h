  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-file.h
  // Example 9.3
#ifndef FILE_H
#define FILE_H
#include <string>
#include "ch9-visitor.h"
  class File {  // abstract element
  public:
    virtual void accept(Visitor& v) = 0; // { v.visit(this); } 
    virtual ~File();
    string name() const;
  protected:
    File(const string&);
  private:
    string name_;
  };
#endif

