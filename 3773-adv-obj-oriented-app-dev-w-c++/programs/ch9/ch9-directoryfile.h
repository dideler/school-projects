  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-directoryfile.h
  // Example 9.3
#ifndef DIRECTORYFILE_H
#define DIRECTORYFILE_H
#include "ch9-file.h"
#include "ch9-visitor.h"
#include <list>
#include <string>
#include <stdexcept>

  class Directory : public File {
  public:
    virtual void accept(Visitor&);
    virtual void add(File*) throw(range_error);
    virtual void remove(File*) throw(range_error);
    virtual ~Directory();
    typedef list<File*>::iterator FileIterator;
    Directory(const string&);
    void show() const;
  private:
    list<File*> children_;
  };
#endif

