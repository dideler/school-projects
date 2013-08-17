/**
 * COMP 3773 - Assignment 6 - Exercise 8.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface (declarations) of the PointList class.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date August 2013
 * @version 1.0
 */

#ifndef POINTLIST_H_
#define POINTLIST_H_

#include "8.5-safelist.h"

class Point;

// A class that represents a list of points using the SafeList class which is
// dervied from std::list with added exception handling.
class PointList : public SafeList<Point> {};

#endif
