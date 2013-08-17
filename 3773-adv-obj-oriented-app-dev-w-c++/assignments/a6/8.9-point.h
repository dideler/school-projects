/**
 * COMP 3773 - Assignment 6 - Exercise 8.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface (declarations) of the basic Point class.
 * A simple 3-dimensional point with some useful operations.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date August 2013
 * @version 1.0
 */

#ifndef POINT_H_
#define POINT_H_

#include <ostream>
using std::ostream;

const double EPSILON = 1e-9; // Small number for floating point equality checks.

// A 3D point in the Cartesian coordinate system.
class Point
{
 public:
  // Creates a point with the given x, y, and z coordinates,
  // or a point at the origin (0,0,0) if no coordinates are given.
  Point(double x = 0, double y = 0, double z = 0);

  // Alternative equality check, calculated using distance squared.
  bool isEqual(const Point &other) const;

  // Returns the Euclidean distance between this point and another point.
  double distance(const Point &other) const;
  
  // Returns the distance squared between this point and another point.
  // Cheaper than the actual distance (skips the square root operation).
  double distanceSquared(const Point &other) const;

  // Accessors
  inline double x() const { return x_; }
  inline double y() const { return y_; }
  inline double z() const { return z_; }

  // Mutators
  inline void set_x(double x) { x_ = x; }
  inline void set_y(double y) { y_ = y; }
  inline void set_z(double z) { z_ = z; }

 private:
  double x_;
  double y_;
  double z_;

  // Overload the << operator to print a point.
  friend ostream &operator<<(ostream &out, const Point &p);
};

// Helpers. Implmented as non-member non-friend functions to decrease the
// quantity of code accessing private/protected data, increasing the
// encapsulation of the class. If the public interface of the class cannot be
// used for whatever reason, consider making it either member or friend.
// Note that it's often enough to only have the overloaded operators == and < as
// friends, and use those to overload the other operators but as non-members.
// See http://stackoverflow.com/questions/4421706/operator-overloading/4421729#4421729

// Returns the square of a number.
inline double sq(const double &x) { return x * x; }

// True if two points are (roughly) equivalent.
bool operator==(const Point &a, const Point &b);

// True if two points are not equivalent.
bool operator!=(const Point &a, const Point &b);

#endif
