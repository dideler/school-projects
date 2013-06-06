/**
 * COMP 3773 - Assignment 2 - Exercise 4.4 using namespaces
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef FLOWER_H_
#define FLOWER_H_

#include <string>

namespace item {

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

} // namespace item

#endif
