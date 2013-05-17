/**
 * COMP 3773 - Assignment 1 - Exercise 3.10
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#include "3.10-gift.h"

int main()
{
  // Test constructors
  Gift book(Book("A Game of Thrones", 14.95));
  book.print();
  Gift flower(Flower("Tulip", 3.95, Flower::Colour::BLUE));
  flower.print();

  // Test copy constructors
  Gift book_copy(book);
  book_copy.print();
  Gift flower_copy(flower);
  flower_copy.print();

  // Test copy assignment operator
  Gift another_book_copy = book;
  another_book_copy.print();
  Gift another_flower_copy = flower;
  another_flower_copy.print();
}
