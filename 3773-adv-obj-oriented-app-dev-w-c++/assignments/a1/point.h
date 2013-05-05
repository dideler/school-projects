#ifndef POINT_H_
#define POINT_H_

#include <ostream>
using std::ostream;

// A 2D point in the Cartesian coordinate system.
class Point
{
 public:
  // Creates a point with the given x and y coordinates, or a point at the
  // origin (0,0) if no coordinates are given.
  Point(double x = 0, double y = 0);

  // Returns the Euclidean distance between this point and another point.
  double distance(const Point &other) const;
 private:
  double x_, y_;

  // Let the Line class access (private) data members directly.
  friend class Line;

  // Overload the << operator to print a point.
  friend ostream &operator<<(ostream &out, const Point &p);
};


#endif
