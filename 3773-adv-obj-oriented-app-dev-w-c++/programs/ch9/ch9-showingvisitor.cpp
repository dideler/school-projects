  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-showingvisitor.cpp
  // Example 9.3
 #include "ch9-showingvisitor.h"
 #include "ch9-regularfile.h"
 #include "ch9-specialfile.h"
 #include "ch9-directoryfile.h"

  void ShowingVisitor::visit(RegularFile* f) {
    f->cat();
  }      

  void ShowingVisitor::visit(SpecialFile* f) { }
    
  void ShowingVisitor::visit(Directory* f) { }
  //ShowingVisitor::ShowingVisitor(const string& s) : name_(s) {}

