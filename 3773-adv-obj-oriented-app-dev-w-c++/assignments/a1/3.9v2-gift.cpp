/**
 * COMP 3773 - Assignment 1 - Exercise 3.9 (v2, not for grading)
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#include <iomanip>
#include "3.9v2-gift.h"

Gift::Gift(Book book) : book_(book) {}

Gift::Gift(Flower flower) : flower_(flower) {}

//Gift::Gift(std::string name, double price, Colour colour)
//  : Flower(name, price, colour) {}

std::ostream &operator<<(std::ostream &out, const Gift &obj)
{
  // It would be better to set a gift type than to check the name,
  // but this is good enough for non-production code.
  if (obj.book_.name() != "Unknown")
    return out << obj.book_;
  return out << obj.flower_;
}
