/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
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
