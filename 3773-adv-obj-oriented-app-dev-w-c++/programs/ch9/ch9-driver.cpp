  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Example 9.3 - main program
#include <iostream>
using namespace std;
#include <string>
#include "ch9-regularfile.h"
#include "ch9-specialfile.h"
#include "ch9-countingvisitor.h"
#include "ch9-showingvisitor.h"
#include "ch9-directoryfile.h"

int main() {
  // create a structure
  Directory* root = new Directory("root");
  RegularFile* f = new RegularFile("regA");
  f->insert(string("reg regA"));
  root->add(f);
  f = new RegularFile("regB");
  f->insert(string("reg regB"));
 root->add(f);
 root->add(new SpecialFile("spA"));
 root->add(new SpecialFile("spB"));
 Directory* r = new Directory("left");
 root->add(r);
 r->add(f);
 root->show();
 
  CountingVisitor cv;
  ShowingVisitor sw;
 
  root->accept(cv);
  root->accept(sw);
  cout << "There are " << cv.getRegular() << " regular files" << endl;
  cout << "There are " << cv.getSpecial() << " special files" << endl;
}
 
