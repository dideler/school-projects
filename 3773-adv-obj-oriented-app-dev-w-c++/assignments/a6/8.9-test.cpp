/**
 * COMP 3773 - Assignment 6 - Exercise 8.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Simple tests for the PointList and Point classes.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date August 2013
 * @version 1.0
 */

#include <iostream>
using namespace std;

//#include "8.9-pointlist.h"
#include "8.9-point.h" // TODO

int main()
{
  Point p1(-7, -4, 3);
  Point p2(17, 6, 2.5);
  Point p3(-7, -4, 3);
  cout << boolalpha;
  cout << p1 << " == " << p2 << " " << (p1 == p2) << endl;
  cout << p1 << " == " << p3 << " " << (p1 == p3) << endl;
  cout << p1 << " isEqual " << p2 << " " << p1.isEqual(p2) << endl;
  cout << p1 << " isEqual " << p3 << " " << p1.isEqual(p3) << endl;
  cout << "distance " << p1 << " to " << p2 << " = " << p1.distance(p2) << endl;
}
