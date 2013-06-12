  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-countingvisitor.cpp
  // Example 9.3
#include "ch9-countingvisitor.h"
// #include <iostream>
// using namespace std;
#include "ch9-regularfile.h"

    void CountingVisitor::visit(RegularFile* f) {
    ++regular_;
  }
  void CountingVisitor::visit(SpecialFile* f) {
    ++special_;
  }

  void CountingVisitor::visit(Directory* f) { }

  int CountingVisitor::getSpecial() const {
    return special_;
 }

 int CountingVisitor::getRegular() const {
   return regular_;
 }

