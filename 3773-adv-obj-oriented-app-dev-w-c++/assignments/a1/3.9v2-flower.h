/**
 * COMP 3773 - Assignment 1 - Exercise 3.9 (v2, not for grading)
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#ifndef FLOWER_H_
#define FLOWER_H_

#include "3.9v2-item.h"

class Flower : public Item
{
 public:
  enum class Colour {RED, GREEN, BLUE, WHITE};
  Flower();
  Flower(std::string name, double price, Colour colour);
  std::string colour() const;
 private:
  void print(std::ostream &out) const;
  Colour colour_;
};

#endif
