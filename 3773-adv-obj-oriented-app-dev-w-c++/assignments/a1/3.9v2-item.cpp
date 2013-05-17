/**
 * COMP 3773 - Assignment 1 - Exercise 3.9 (v2, not for grading)
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#include "3.9v2-item.h"

Item::Item() : name_("Unknown") {}

Item::Item(std::string name, double price) : name_(name), price_(price) {}

Item::~Item() {}

std::string Item::name() const { return name_; }

double Item::price() const { return price_; }

// Virtual friend functions don't exist, so instead we make the print function
// polymorphic and call it from here.
std::ostream &operator<<(std::ostream &out, const Item &item)
{
  item.print(out);
  return out;
}
