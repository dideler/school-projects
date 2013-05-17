/**
 * COMP 3773 - Assignment 1 - Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#include "3.9-gift.h"

int main()
{
  Gift book(Book("LOTR", 14.95));
  book.print();
  Gift flower(Flower("Tulip", 3.95, Flower::Colour::BLUE));
  flower.print();
}
