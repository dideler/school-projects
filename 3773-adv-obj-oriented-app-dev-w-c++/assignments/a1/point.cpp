#include <cmath>
#include "point.h"

Point::Point(double x, double y) : x_(x), y_(y) {}

double Point::distance(const Point &other) const
{
  return hypot(x_ - other.x_, y_ - other.y_);
  // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
}

ostream &operator<<(ostream &out, const Point &p)
{
  return out << "(" << p.x_ << ", " << p.y_ << ")";
}
