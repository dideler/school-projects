/**
 * Exercise 3.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * Test if two lines are parallel.
 * Test if two lines are perpendicular.
 * Find the intersection of two lines (assume not called if already parallel).
 * Find shortest distance between a line and a point.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include "point.h"
#include "line.h"

int main()
{
  vector<Point> points;
  points.push_back(Point(2, 2)); // P0
  points.push_back(Point(4, 3)); // P1
  points.push_back(Point(2, 4)); // P2
  points.push_back(Point(6, 6)); // P3
  points.push_back(Point(2, 6)); // P4
  points.push_back(Point(6, 5)); // P5
  points.push_back(Point(8, 6)); // P6
  points.push_back(Point(1, 3)); // P7
  points.push_back(Point(0, 1)); // P8
  points.push_back(Point(3, 7)); // P9
  points.push_back(Point(0, 4)); // P10
  points.push_back(Point(8, 0)); // P11
  points.push_back(Point(1, 2)); // P12
  points.push_back(Point(3, 2)); // P13

  /*                                      
 (y)                                       
  7               P9                      7
  6           P4              P3      P6  6
  5                           P5          5
  4   P10     P2                          4
  3       P7          P1                  3
  2       P12 P0  P13                     2
  1   P8                                  1
  0                                   P11 0
 -1   0   1   2   3   4   5   6   7   8   9 (x)
  */

  cout << "Points:" << endl;
  for (auto point : points)
  {
    cout.width(2);
    static int count;
    cout << count << ": " << point << endl;
    ++count;
  }
  cout << endl;

  // Distance test.
  double d = points[0].distance(points[5]);
  cout << "Euclidean distance between " << points[0] << " and " << points[5] << " = " << d << "\n" << endl;
  assert(d == 5.0);
 
  vector<Line> lines;
  lines.push_back(Line(points[0], points[1]));
  lines.push_back(Line(points[0], points[2]));
  lines.push_back(Line(points[2], points[3]));
  lines.push_back(Line(points[2], points[4]));
  lines.push_back(Line(points[7], points[1]));
  lines.push_back(Line(points[0], points[5]));
  lines.push_back(Line(points[8], points[9]));
  lines.push_back(Line(points[10], points[11]));
  lines.push_back(Line(points[12], points[13]));

  cout << "Lines:" << endl;
  for (auto line : lines)
  {
    cout.width(2);
    static int count;
    cout << count << ": " << line << endl;
    ++count;
  }
  cout << endl;

  // Parallel tests.
  bool b = lines[0].isParallel(lines[1]);
  cout << "line 0 (" << lines[0] << ") and line 1 (" << lines[1] << ") are parallel? " << boolalpha << b << endl;
  assert(b == false); // This is more readable than assert(!b).
  b = lines[1].isParallel(lines[1]);
  cout << "line 1 (" << lines[1] << ") and line 1 (" << lines[1] << ") are parallel? " << boolalpha << b << endl;
  assert(b == true); 
  b = lines[0].isParallel(lines[2]);
  cout << "line 0 (" << lines[0] << ") and line 2 (" << lines[2] << ") are parallel? " << boolalpha << b << endl;
  assert(b == true);
  cout << endl;

  // Perpendicular tests.
  b = lines[2].isPerpendicular(lines[4]);
  cout << "line 2 (" << lines[2] << ") and line 4 (" << lines[4] << ") are perpendicular? " << boolalpha << b << endl;
  assert(b == false);
  b = lines[4].isPerpendicular(lines[5]);
  cout << "line 4 (" << lines[4] << ") and line 5 (" << lines[5] << ") are perpendicular? " << boolalpha << b << endl;
  assert(b == false);
  b = lines[1].isPerpendicular(lines[4]);
  cout << "line 1 (" << lines[1] << ") and line 4 (" << lines[4] << ") are perpendicular? " << boolalpha << b << endl;
  assert(b == true);
  b = lines[6].isPerpendicular(lines[7]);
  cout << "line 6 (" << lines[6] << ") and line 7 (" << lines[7] << ") are perpendicular? " << boolalpha << b << endl;
  assert(b == true);
  cout << endl;
  
  // Intersection tests.
  Point p;
  b = lines[0].intersects(lines[1]);
  assert(b == true);
  p = lines[0].getIntersection(lines[1]);
  cout << "line 0 (" << lines[0] << ") and line 1 (" << lines[1] << ") intersect? " << boolalpha << b << ", at " << p << endl;
  b = lines[1].intersects(lines[3]);
  assert(b == false);
  cout << "line 1 (" << lines[1] << ") and line 3 (" << lines[3] << ") intersect? " << boolalpha << b << ", are the same line so intersect at every point" << endl;
  b = lines[1].intersects(lines[8]);
  assert(b == true);
  p = lines[1].getIntersection(lines[8]);
  cout << "line 1 (" << lines[1] << ") and line 8 (" << lines[8] << ") intersect? " << boolalpha << b << ", at " << p << endl;
  cout << endl;

  // Shortest distance to point test.
  d = lines[2].getShortestDistToPoint(points[0]);
  cout.precision(3);
  cout << "Euclidean distance from closest point on line 2 (" << lines[2] << ") to point 0 " << points[0] << " = " << d << endl;
}
