// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.5

#include "ex8.5.property.cpp"

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << " filename" << endl;
    return 1;
  }

  Property p;
  if (!p.load(argv[1]))
  {
    cerr << "can't load " << argv[1] << endl;
    return 2;
  }

  string name;
  string value;
  while(true)
  {
    cout << "enter name (. to finish) " << endl;
    cin >> name;
    if (name == ".") break;
    if (p.getProperty(name, value)) cout << value << endl;
    else cout << "not found " << endl;
  }

  p.add(string("zz"), string("bb"));
  if (!p.list("junk.dat")) cout << "list failed" << endl;
}
