// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
//
// Simple tester for file operations
// Filename is passed on the command line.
// First, a class variable is created to test all operations.
// Second, a pointer to the class variable is assigned to a class object
// Third, the object pointed to by a pointer is deleted, and then assigned another object
// This program can be compiled using conditional compilation (macro DEB)
// If this macro is defined then the program shows whether or not the cache is used

//#include <iostream>
//using namespace std;
#include "ex3.3.fileops.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "usage " << argv[0] << " filename" << endl;
    return 1;
  }

  FileOps f(argv[1]); // stack
  cout << "words " << f.words() << endl;
  cout << "characters " << f.chars() << endl;
  cout << "lines " << f.lines() << endl << endl;

  FileOps* p = new FileOps(argv[1]); // heap
  cout << "words " << p->words() << endl;
  cout << "characters " << p->chars() << endl;
  cout << "lines " << p->lines() << endl << endl;
  delete p;

  p = new FileOps(argv[1]);
  cout << "words " << p->words() << endl;
  cout << "characters " << p->chars() << endl;
  cout << "lines " << p->lines() << endl << endl;
  delete p;
}
