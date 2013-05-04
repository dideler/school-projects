// A .cc file should contain more information about implementation details or
// discussions of tricky algorithms.

// - test if two lines are parallel
// - test if two lines are perpendicular
// - find the intersection of two lines (assume not called if already parallel)
// - find shortest distance between a line and a point
// - handle all kinds of lines, including of the form y=b and x=c

#include "line.h"

Line::Line(const Point &p1, const Point &p2)
{
  if (isEqual(p1.x, p2.x))
  {
    a_ = 1.0;
    b_ = 0.0;
    c_ = -p1.x;
  }
  else
  {
    a_ = -static_cast<double>(p1.y - p2.y) / (p1.x - p2.x);
    b_ = 1.0;
    c_ = -static_cast<double>(a_ * p1.x) - p1.y;
  }
}

Line::Line(double x1, double y1, double x2, double y2)
{
  if (isEqual(x1, x2))
  {
    a_ = 1.0;
    b_ = 0.0;
    c_ = -x1;
  }
  else
  {
    a_ = -static_cast<double>(y1 - y2) / (x1 - x2);
    b_ = 1.0;
    c_ = -static_cast<double>(a_ * x1) - y1;
  }
}

Line::Line(const Point &p, double m)
{
  a_ = -m;
  b_ = 1.0;
  c_ = -((a_ * p.x) + (b_ * p.y));
}

// TODO: try with default constructor - difference?
Line::Line(const Line &other) : a_(other.a_), b_(other.b_), c_(other.c_) {}

Line::~Line() {} // TODO: not needed

// Two lines are parallel if the slopes are the same.
// Checks coefficients a & b.
bool Line::isParallel(const Line &other) const
{
  return isEqual(a_, other.a_) && isEqual(b_, other.b_);
}

// Two lines are parallel if they meet at a right angle.
// Equations of perpendicular lines have either
// - one being horizontal and the other vertical, or
// - slopes that multiply to give -1
bool Line::isPerpendicular(const Line &other) const
{
  // Handle the case of horizontal and vertical lines.
  if ((isHorizontal() && other.isVertical()) ||
      (isVertical() && other.isHorizontal()))
  {
    return true;
  }
  return -(a_) * -(other.a_) == -1;
}

Point Line::getIntersection(const Line &other) const
  throw(NoIntersectException)
{
  if (!intersects(other)) throw NoIntersectException();
  Point p;
  // Solve system of 2 linear algebraic equations with 2 unknowns.
  p.x = (other.b_ * c_ - b_ * other.c_) / (other.a_ * b_ - a_ * other.b_);
  if (fabs(b_) > EPS)
    p.y = -(a_ * p.x + c_);
  else
    p.y = -(other.a_ * p.x + other.c_);
  return p;
}

double Line::getShortestDistToPoint(const Point &p) const
{
  return distance(findClosestPoint(p), p);
}

double Line::distance(const Point &p1, const Point &p2) const
{
  return hypot(p1.x - p2.x, p1.y - p2.y);
  // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
}

// A horizontal line has coefficients a == 0 anb b != 0.
bool Line::isHorizontal() const
{
  return fabs(a_) < EPS && fabs(b_) > EPS;
}

// A vertical line has coefficients a != 0 anb b == 0.
bool Line::isVertical() const
{
  return fabs(a_) > EPS && fabs(b_) < EPS;
}

bool Line::onSameLine(const Line &other) const
{
  return isParallel(other) && isEqual(c_, other.c_);
}

Point Line::findClosestPoint(const Point &p) const
{
  if (isVertical()) // Try just checking b coefficient if any issues.
    return Point(-c_, p.y);
  if (isHorizontal()) // Check just a coefficient if issues FIXME
    return Point(p.x, -c_);

  // Otherwise the 2 lines must intersect at some point.
  // Create a line perpendicular to current line and passing through point p.
  // The intersection point of the two lines is the closest point.
  Line perpendicular(p, 1 / a_);
  if (intersects(perpendicular))
    return getIntersection(perpendicular);
  return Point(); // FIXME improve, throw exception instead
}

bool Line::intersects(const Line &other) const
{
  if (onSameLine(other)) return false; // All points intersect!
  if (isParallel(other)) return false;
  return true;
}

// To see some limitations of this method, read
// http://stackoverflow.com/questions/17333/most-effective-way-for-float-and-double-comparison
bool Line::isEqual(const double a, const double b) const
{
  return fabs(a - b) < EPS;
}
