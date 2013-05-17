/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#include <iostream>
#include <iomanip>
#include "3.9-gift.h"

Gift::Gift(Book book) : book_(book) {}

Gift::Gift(Flower flower) : flower_(flower) {}

void Gift::print() const
{
  if (!book_.name().empty())
  {
    std::cout << "Book name: " << book_.name() << "\n"
      << "Price: $" << std::fixed << std::setprecision(2) << book_.price()
      << std::endl;
  }
  else
  {
    std::cout << "Flower name: " << flower_.name() << "\n"
      << "Colour: " << flower_.colour() << "\n"
      << "Price: $" << std::fixed << std::setprecision(2) << flower_.price()
      << std::endl;
  }
}
