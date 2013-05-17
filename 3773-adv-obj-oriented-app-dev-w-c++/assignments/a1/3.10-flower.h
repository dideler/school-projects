/**
 * COMP 3773 - Assignment 1 - Exercise 3.10
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#ifndef FLOWER_H_
#define FLOWER_H_

#include <string>

class Flower
{
 public:
  enum Colour {RED, GREEN, BLUE};
  Flower();
  Flower(std::string name, double price, Colour colour);
  std::string name() const;
  double price() const;
  std::string colour() const;
 private:
  std::string name_;
  double price_;
  Colour colour_;
};

#endif
