// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex4.1a.point.h
//
// Like ex4.1, but class Point also knows which coordinate system it is using.

#ifndef POINTA_H
#define POINTA_H
class Point { 
public:
  static Point cartesian(double, double);
  static Point polar(double, double);
  enum System {CARTESIAN, POLAR}; // Enums for the type.
  const System kind; // Constant enum type.
  double x() const;
  double y() const;
private:
  Point(double, double, System);
  double x_;
  double y_;
};
#endif

