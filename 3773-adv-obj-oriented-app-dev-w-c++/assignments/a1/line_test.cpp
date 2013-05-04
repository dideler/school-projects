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
  for (auto point : points)
    cout << point << endl;

  vector<Line> lines;
}
