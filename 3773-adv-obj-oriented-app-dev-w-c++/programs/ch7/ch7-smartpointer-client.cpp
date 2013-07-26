  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch7.smartpointer.client.cpp
  #include "ch7.smartpointer.cpp"
  #include "ch7.point.h"

#include <iostream>
using namespace std;

  int main() {

  Handle<Point> hp1(new Point(1, 2));
  cout << hp1->getX() << endl;  // hp1.operator->()->getX();
  Handle<Point> hp2(hp1); // share points
  Handle<Point> hp3(new Point(3, 4));
  hp3 = hp2;    // deallocate point (3, 4)
  cout << hp2->getY() << " " << hp3->getY() << endl;
 }
