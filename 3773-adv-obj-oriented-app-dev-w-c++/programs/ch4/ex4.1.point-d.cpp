// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File:  ex4.1.point-d.cpp
// Simple test program for creating a point, using instantiating operations.

#include <iostream>
using namespace std;
#include "ex4.1.point.h"

int main()
{
  Point p1 = Point::cartesian(5.7, 1.2);  
  Point p2 = Point::polar(5.7, 0.2);  

  cout << "x: " << p1.x() << " y: " << p1.y() << endl;
  cout << "x: " << p2.x() << " y: " << p2.y() << endl;
}

