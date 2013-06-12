  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
 // File: ch9-countingvisitor.h
 // Example 9.3
#ifndef COUNTINGVISITOR_H
#define COUNTINGVISITOR_H
#include "ch9-visitor.h"
  class CountingVisitor : public Visitor { // implements
  // counts the number of regular and special files
  public:
    virtual void visit(RegularFile*);
    virtual void visit(SpecialFile*);
    virtual void visit(Directory*);
    CountingVisitor() : regular_(0), special_(0) {}
    int getSpecial() const;
    int getRegular() const;
  private:
    int regular_;
    int special_;
  };
#endif

