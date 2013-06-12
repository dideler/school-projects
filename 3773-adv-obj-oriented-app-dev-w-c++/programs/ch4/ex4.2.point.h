// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex4.2.point.h
//
// Similar to ex4.1, but class Point returns pointers to objects in the
// instantiating operations, rather than objects.

#ifndef POINT_H
#define POINT_H
class Point
{
 public:
  static Point* cartesian(double, double);
  static Point* polar(double, double);
  double x() const;
  double y() const;
 private:
  Point(double, double);
  Point(const Point&);
  double x_;
  double y_;
};
#endif
