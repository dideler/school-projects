/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#include "item.h"

Item::Item(string name, double price) : name_(name), price_(price) {}

Item::~Item() {}

string Item::name() const { return name_; }

double Item::price() const { return price_; }

// Virtual friend functions don't exist, so instead we make the print function
// polymorphic and call it from here.
ostream &operator<<(ostream &out, const Item &item)
{
  item.print(out);
  return out;
}

