/**
 * COMP 3773 - Assignment 5 - Exercise 7.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Testing template class List using
 * - a primitive data type (integers) in a 2D list (list of lists of ints)
 * - concrete type Point
 * - concrete type Segment (i.e. line segment)
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#include <iostream>
using namespace std;

#include "7.11-point.h"
#include "7.11-segment.h" 
#include "7.11-list.h" 
//#include "7.11-list.cpp" // Necessary to avoid linker errors due to templates.
                         // Alternative solutions exist: http://goo.gl/ObPUu5
using namespace mylist;

int main()
{
  Point p0;
  Point p1(1, 2, 3);
  cout << p0 << endl;
  cout << p1 << endl;

  Segment s(p0, p1);
  cout << s << endl;

  //List<Point> points;
  //List<Segment> segments;
  //List<List<int>> ints;
  List<int> ints;

  for (int i = 1; i <= 5; ++i)
    ints.push_front(i);

  for (auto it = ints.begin(); it != ints.end(); ++it)
    cout << *it << ' ';
  cout << endl;


  cout << "front = " << ints.front() << endl;
  if (!ints.empty())
  {
    ints.pop_front();
    cout << "popped front" << endl;
  }
  cout << "front = " << ints.front() << endl;
  
  cout << "back = " << ints.back() << endl;

  cout << "size = " << ints.size() << endl;

  for (int i = 0; i < ints.size(); ++i)
    cout << "[" << i << "] = " << ints[i] << endl;
  
  for (auto it = ints.begin(); it != ints.end(); ++it)
    cout << *it << ' ';
  cout << endl;
}
