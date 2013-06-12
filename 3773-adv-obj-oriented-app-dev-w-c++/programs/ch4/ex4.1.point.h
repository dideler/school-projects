// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex4.1.point.h
//
// There are two commonly used coordinate systems in a two dimensional space: 
// Cartesian (using x and y coordinates) and Polar (using a radius and an angle). 
//
// Using the Instantiating Operations Idiom, I hide the constructors and provide 
// two static functions to construct respectively the Cartesian and the polar system. 
// Both these functions return new objects and so they are designed following the 
// Returning New Object Idiom 3.5:

#ifndef EX4_1_POINT_H
#define EX4_1_POINT_H
class Point { 
public:
  static Point cartesian(double, double);      //instantiating operation
  static Point polar(double, double);          //instantiating operation
  double x() const;
  double y() const;
private:
  Point(double, double);
  double x_;
  double y_;
};
#endif
