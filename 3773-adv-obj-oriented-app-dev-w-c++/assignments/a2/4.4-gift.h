/**
 * COMP 3773 - Assignment 2 - Exercise 4.4 using namespaces
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef GIFT_H_
#define GIFT_H_

#include "4.4-book.h"
#include "4.4-flower.h"

namespace item {

class Gift
{
 public:
  enum GiftType { BOOK, FLOWER };
  static Gift book(std::string name, double price); // Instantiating operation.
  static Gift flower(std::string name, double price, Flower::Colour colour);
  void print() const;
  const GiftType type;
 private:
  explicit Gift(Book book, GiftType btype);
  explicit Gift(Flower flower, GiftType ftype);
  Book book_;
  Flower flower_;
};

} // namespace item

#endif
