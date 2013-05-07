/**
 * Exercise 3.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#include "line.h"

Line::Line(const Point &p1, const Point &p2)
{
  if (isEqual(p1.x_, p2.x_))
  {
    a_ = 1.0;
    b_ = 0.0;
    c_ = -p1.x_;
  }
  else
  {
    a_ = -static_cast<double>(p1.y_ - p2.y_) / (p1.x_ - p2.x_);
    b_ = 1.0;
    c_ = -static_cast<double>(a_ * p1.x_) - p1.y_;
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
  c_ = -((a_ * p.x_) + (b_ * p.y_));
}

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
  p.x_ = (other.b_ * c_ - b_ * other.c_) / (other.a_ * b_ - a_ * other.b_);
  if (fabs(b_) > EPS)
    p.y_ = -(a_ * p.x_ + c_);
  else
    p.y_ = -(other.a_ * p.x_ + other.c_);
  return p;
}

double Line::getShortestDistToPoint(const Point &p) const
{
  return p.distance(findClosestPoint(p));
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
    return Point(-c_, p.y_);
  if (isHorizontal()) // Check just a coefficient if issues FIXME
    return Point(p.x_, -c_);

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

ostream &operator<<(ostream &out, const Line &l)
{
  return out << l.a_ << "x + " << l.b_ << (l.c_ < 0 ? "y " : "y + ") << l.c_ << " = 0";
//    "y + " << l.c_ << " = 0";
}
