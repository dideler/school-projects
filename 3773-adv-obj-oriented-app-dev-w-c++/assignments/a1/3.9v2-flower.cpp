/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#include <iomanip>
#include "3.9v2-flower.h"

Flower::Flower() {}

Flower::Flower(std::string name, double price, Colour colour)
  : Item(name, price), colour_(colour) {}

std::string Flower::colour() const
{
  switch(colour_) // Not the best way to do this, but good enough for now.
  {
    case Colour::RED:
      return "Red";
    case Colour::GREEN:
      return "Green";
    case Colour::BLUE:
      return "Blue";
    case Colour::WHITE:
      return "White";
    default:
      return "Other";
  }
}

// Printing the price uses fixed-point notation and 2 decimal places precision.
void Flower::print(std::ostream &out) const
{
  out << "Flower Name: " << name_ 
      << "\nColour: " << colour()
      << "\nPrice: $" << std::fixed << std::setprecision(2) << price_;
}
