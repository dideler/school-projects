/**
 * COMP 3773 - Assignment 2 - Exercise 4.4 using namespaces
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * This exercise uses namespaces and instantiating operations.
 * The creational process is overtaken by static functions (instantiating
 * operations) that create and return an object. All constructors are hidden
 * from the interface. This is sometimes more convenient than overloading
 * constructors.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "4.4-gift.h"

int main()
{
  item::Gift gift1 = item::Gift::book("LOTR", 14.95);
  item::Gift gift2 = item::Gift::flower("Tulip", 3.95, item::Flower::Colour::BLUE);
  gift1.print();
  gift2.print();
}
