  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-visitor.h
  // Example 9.3
#ifndef VISITOR_H
#define VISITOR_H
class RegularFile;
class SpecialFile;
class Directory;
  class Visitor {  // abstract
  public:
    virtual void visit(RegularFile*) = 0;
    virtual void visit(SpecialFile*) = 0;
    virtual void visit(Directory*) = 0;
  };
#endif

