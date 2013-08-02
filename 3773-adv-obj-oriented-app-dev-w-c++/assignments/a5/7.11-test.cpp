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
 * @date July-August 2013
 * @version 1.1
 */

#include <iostream>
using namespace std;

#include "7.11-point.h"
#include "7.11-segment.h" 
#include "7.11-list.h" 
using namespace mylist;

// Prints the contents of the list.
template <typename T>
void print(List<T> &list)
{
  if (!list.empty())
  {
    for (auto it = list.begin(); it != list.end(); ++it)
      cout << *it << ' ';
    cout << endl;
  }
}

// Prints the contents of a two-dimensional list.
template <typename T>
void print2d(List<T> &list)
{
  if (!list.empty())
  {
    for (int i = 0; i < list.size(); ++i)
    {
      for (auto it = list[i].begin(); it != list[i].end(); ++it)
        cout << *it << ' ';
      if (i < list.size() - 1) cout << ", ";
    }
    cout << endl;
  }
}

int main()
{
  // Test List with a primitive data type.
  List<int> ints;
  for (int i = 1; i <= 5; ++i) ints.push_front(i);
  cout << "ints = "; print(ints);
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

  // Test List with Points.
  Point p0; // 0, 0, 0
  Point p1(1, 2, 3);
  Point p2(3, 2, 1);
  Point p3(5, 5, 5);
  List<Point> points;
  points.push_front(p0);
  points.push_front(p1);
  points.push_front(p2);
  points.push_front(p3);
  cout << "\npoints = "; print(points);
  cout << "size = " << points.size() << endl;
  points.clear();
  print(points); // Shouldn't print anything.

  // Test List with Segments.
  Segment s0(p0, p1);
  Segment s1(p1, p2);
  Segment s2(p2, p3);
  Segment s3(p0, p3);
  List<Segment> segments;
  Segment s(Point(1,2,3), Point(3,2,1));
  segments.push_front(s);
  segments.push_front(s0);
  segments.push_front(s1);
  segments.push_front(s2);
  segments.push_front(s3);
  cout << "\nsegments = "; print(segments);
  cout << "size = " << segments.size() << endl;
  segments.clear();
  print(segments); // Shouldn't print anything.

  // Test copy and assign.
  List<int> ints0(ints); // Note: `List<int> ints0 = ints` also works.
  cout << "\nints0 (copied) = "; print(ints0);

  ints0 = ints; 
  cout << "ints0 (assigned) = "; print(ints0);

  // Test two-dimensional List.
  List<int> ints1;
  for (int i = 5; i >= 1; --i) ints1.push_front(i);
  cout << "ints1 = "; print(ints1);

  List<int> ints2;
  for (int i = 1; i <= 5; ++i) ints2.push_front(i * 2);
  cout << "ints2 = "; print(ints2);

  List<List<int>> list_of_ints; // Note: >> is allowed since C++11.
  list_of_ints.push_front(ints0);
  list_of_ints.push_front(ints1);
  list_of_ints.push_front(ints2);
  cout << "\nlist_of_ints = "; print2d(list_of_ints);
  cout << "size = " << list_of_ints.size() << endl;
  cout << "list_of_ints[0] = "; print(list_of_ints[0]);
  cout << "back = "; print(list_of_ints.back());
}
