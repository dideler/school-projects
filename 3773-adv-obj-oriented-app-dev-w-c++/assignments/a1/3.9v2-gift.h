/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#ifndef GIFT_H_
#define GIFT_H_

#include "3.9v2-book.h"
#include "3.9v2-flower.h"

class Gift
{
 public:
  Gift(Book book);
  //Gift(std::string name, double price); // Add if convenient.
  Gift(Flower flower);
  //Gift(std::string name, double price, Colour colour); // Add if convenient.
 private:
  friend std::ostream &operator<<(std::ostream &out, const Gift &obj);
  Book book_;
  Flower flower_;
};

#endif
