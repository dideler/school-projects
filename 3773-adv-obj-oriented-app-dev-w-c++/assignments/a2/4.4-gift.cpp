/**
 * COMP 3773 - Assignment 2 - Exercise 4.4 using namespaces
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include <iostream>
#include <iomanip>
#include "4.4-gift.h"

namespace item {

Gift::Gift(Book book, GiftType btype) : type(btype), book_(book) {}

Gift::Gift(Flower flower, GiftType ftype) : type(ftype), flower_(flower) {}

Gift Gift::book(std::string name, double price)
{
  return Gift(Book(name, price), BOOK);
}

Gift Gift::flower(std::string name, double price, Flower::Colour colour)
{
  return Gift(Flower(name, price, colour), FLOWER);
}

void Gift::print() const
{
  if (type == BOOK) // GiftType::Book also works.
  {
    std::cout << "Book name: " << book_.name() << "\n"
      << "Price: $" << std::fixed << std::setprecision(2) << book_.price()
      << std::endl;
  }
  else if (type == FLOWER)
  {
    std::cout << "Flower name: " << flower_.name() << "\n"
      << "Colour: " << flower_.colour() << "\n"
      << "Price: $" << std::fixed << std::setprecision(2) << flower_.price()
      << std::endl;
  }
  else std::cout << "Unknown gift type" << std::endl;
}

} // namespace item
