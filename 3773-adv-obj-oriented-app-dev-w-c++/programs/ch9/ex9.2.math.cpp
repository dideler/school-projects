  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Example 9.2
 // File: ex9.2.math.cpp
#include "ex9.2.math.h"
#include <cmath>

  double Math::sum(double x, double y) const { 
    return x+y; 
  }
  double Math::sqrt(double x) const { 
    return ::sqrt(x); // call global sqrt
  }

