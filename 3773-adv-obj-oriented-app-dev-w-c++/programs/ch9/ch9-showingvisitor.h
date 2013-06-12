  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-showingvisitor.h
  // Example 9.3
#ifndef SHOWINGVISITOR_H
#define SHOWINGVISITOR_H
#include <string>
#include "ch9-visitor.h"
class RegularFile;
class SpecialFile;
class Directory;
  class ShowingVisitor : public Visitor { // implements
  // shows all files whose name is passed in the constructor
  public:
    virtual void visit(RegularFile*);
    virtual void visit(SpecialFile*);
    virtual void visit(Directory*);
  };
#endif

