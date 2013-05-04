#include "point.h"

Point::Point(double _x, double _y) : x(_x), y(_y) {}

ostream &operator<<(ostream &out, const Point &p)
{
  return out << "(" << p.x << ", " << p.y << ")";
}
