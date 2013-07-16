/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation of the abstract product class.
 * Based on example 6.1.
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "6.3-product.h"
#include <limits>
#include <iostream>

AbstractProduct::~AbstractProduct() {}

// Clears the error flag on cin and ignores the maximum number of characters
// possible until EOL.
void AbstractProduct::clearBuffer() const
{
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
