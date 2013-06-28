// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.1.driver.cpp
//
// Sample main program for exercise 6-1.

#include <iostream>
using namespace std;

#include "ex6.1.cachedapplication.h"
#include "ex6.1.regularapplication.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    cerr << "usage " << argv[0] << " file1 file2" << endl;
    return 1;
  }

  CachedApplication* cached = new CachedApplication(argv[1]);
  cout << "lines in " << argv[1] << " " << cached->lines() << endl;
  cached->clearCache();
  cout << "lines in " << argv[1] << " " << cached->lines() << endl;

  AbstractApplication* regular = new RegularApplication(argv[2]);
  cout << "lines in " << argv[2] << " " << regular->lines() << endl; // AbstractApplication::lines()
}
