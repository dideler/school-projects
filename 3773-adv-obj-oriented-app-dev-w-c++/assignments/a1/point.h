#ifndef POINT_H_
#define POINT_H_

#include <ostream>
using std::ostream;

// A 2D point in the Cartesian coordinate system.
struct Point
{
  double x, y;
  Point(double _x = 0, double _y = 0);
};

// Overload the << operator to print a point.
ostream &operator<<(ostream &out, const Point &p);

#endif
