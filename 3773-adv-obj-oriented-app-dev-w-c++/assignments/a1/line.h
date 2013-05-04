/**
 *  Exercise 3.3
 *  From the book "C++ Programming with Design Patterns Revealed"
 *  
 *  @author Dennis Ideler <ideler.dennis@gmail.com>
 */

// Note that I provided a copy constructor and assignment operator
// because the text book recommends it. The style guide that I follow,
// however, recommends not using them in most cases and disabling them.
// See:
//  http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml?showone=Operator_Overloading#Operator_Overloading
//  http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml?showone=Copy_Constructors#Copy_Constructors


#ifndef LINE_H_
#define LINE_H_

#include <cmath>
#include <stdexcept>
using std::logic_error;

#include "point.h"

const double EPS = 1e-9; // Substitute for 0 in equality checks.

// TODO document functions for the user
// A .h file describes the classes that are declared in the file
// with an overview of what they are for and how they are used.

// Custom exception to be used when calculating the non-existant intersection
// point of two lines.
// TODO: move definition to cpp file
class NoIntersectException : public logic_error
{
 public:
  NoIntersectException() : logic_error("Lines do not intersect") {}

//  virtual const char* what() const throw()
//  {
//    return "The two lines do not intersect.";
//  }
};

// This class contains the representation and common operations for straight
// lines (not line segments, which are lines of finite length).
// A line is represented as coefficients of ax + by + c = 0.
// The line equation y = mx + c is avoided because it's difficult for handling
// all cases due to vertical lines having "infinite" slope.
class Line
{
 public:
  Line(const Point &p1, const Point &p2);
  Line(double x1, double y1, double x2, double y2);
  // Create a line given a point and a gradient/slope of line.
  // Note that this creates a line and not a line segment.
  Line(const Point &p, double m);
  Line(const Line &other);
  //Lines& operator=(const Lines &other); TODO
  ~Line();

  // Returns true if this line and the other are parallel.
  // This method considers a line parallel if the slopes are the same, which
  // means that a line is also parallel to itself.
  // If you follow a different definition, such as the lines always having the
  // same distance apart and never touching, then call this method after
  // verifying that the lines do not intersect.
  bool isParallel(const Line &other) const;

  // Returns true if this line and the other meet at a right angle (90 degrees).
  // In other words, if the lines are orthogonal to each other.
  bool isPerpendicular(const Line &other) const;

  // Returns the intersection point of this line and the other.
  // Throws an exception if the lines do not intersect.
  Point getIntersection(const Line &other) const
    throw(NoIntersectException);

  // Returns the shortest distance between this line and point p.
  double getShortestDistToPoint(const Point &p) const;

 private:
  // The coefficients of the line equation ax + by = c.
  double a_, b_, c_;

  // Returns the Euclidean distance between two points.
  double distance(const Point &p1, const Point &p2) const;

  // Returns true if this line is horizontal.
  bool isHorizontal(void) const;

  // Returns true if this line is vertical.
  bool isVertical(void) const;

  // True if this line and the other are on the same line.
  // In other words, checks if they are the same line.
  bool onSameLine(const Line &other) const;

  // Returns the closest point on this line to point p.
  Point findClosestPoint(const Point &p) const;

  // Returns true if this line intersects with the other.
  // Otherwise the lines are either the same or parallel.
  bool intersects(const Line &other) const;

  // True if two doubles are virtually equal.
  // Helper function; less error-prone than a == b.
  bool isEqual(const double a, const double b) const;
};

#endif
