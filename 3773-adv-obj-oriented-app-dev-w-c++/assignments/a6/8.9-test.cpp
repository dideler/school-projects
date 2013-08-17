/**
 * COMP 3773 - Assignment 6 - Exercise 8.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Simple tests for the Point and PointList classes.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date August 2013
 * @version 1.0
 */

#include <iostream>
using namespace std;

#include "8.9-point.h"
#include "8.9-pointlist.h"

template <typename Container>
void print(const Container &c)
{
  for (const auto &e : c)
    cout << e << ' ';
  cout << endl;
}

int main()
{
  Point p1(-7, -4, 3);
  Point p2(17, 6, 2.5);
  Point p3(-7, -4, 3);

  try
  {
    PointList pl;
    pl.push_back(p1);
    pl.push_back(p2);
    pl.push_back(p3);
    print(pl);

    // Note that std::list doesn't allow you to retrieve elements by index,
    // because it would require iterating through the list which is a linear
    // time operation. So to make the testing code easier to read and
    // understand, I use the Point objects directly instead of awkwardly
    // retrieving them from the list in some arbitrary order to test (note that
    // std::advance is an alternative).
    cout << boolalpha;
    cout << p1 << " == " << p2 << " = " << (p1 == p2) << endl;
    cout << p1 << " == " << p3 << " = " << (p1 == p3) << endl;
    cout << p1 << " isEqual " << p2 << " = " << p1.isEqual(p2) << endl;
    cout << p1 << " isEqual " << p3 << " = " << p1.isEqual(p3) << endl;
    cout << p1 << " distance to " << p2 << " = " << p1.distance(p2) << endl;
  }
  catch (const exception &e) { cout << e.what() << endl; }
}
