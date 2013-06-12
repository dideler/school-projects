// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex4.1a.point-d.cpp
// Simple test program for the modified point class

#include <iostream>
using namespace std;
#include "ex4.1a.point.h"

int main()
{
  Point p = Point::cartesian(1, 2);
  if (p.kind == Point::CARTESIAN)
    cout << "cartesian " << endl;
  cout << "x: " << p.x() << " y: " << p.y() << endl;
}
