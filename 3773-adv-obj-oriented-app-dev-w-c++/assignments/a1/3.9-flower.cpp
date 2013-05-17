/**
 * COMP 3773 - Assignment 1 - Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#include "3.9-flower.h"

Flower::Flower() {}

Flower::Flower(std::string name, double price, Colour colour)
  : name_(name), price_(price), colour_(colour) {}

std::string Flower::name() const { return name_; }

double Flower::price() const { return price_; }

std::string Flower::colour() const
{
  switch(colour_) // Not the best way, but good enough for now.
  {
    case Colour::RED:
      return "Red";
    case Colour::GREEN:
      return "Green";
    case Colour::BLUE:
      return "Blue";
    default:
      return "Other";
  }
}
