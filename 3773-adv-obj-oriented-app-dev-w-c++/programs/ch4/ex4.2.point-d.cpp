// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex4.2.point-d.cpp
// Testing program for the class point

#include <iostream>
using namespace std;
#include "ex4.2.point.h"

int main()
{
  Point* p = Point::cartesian(1,2);
  cout << "x: " << p->x() << " y: " << p->y() << endl;
  delete p;
}

