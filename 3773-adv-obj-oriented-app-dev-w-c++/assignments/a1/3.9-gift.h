/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#ifndef GIFT_H_
#define GIFT_H_

#include "3.9-book.h"
#include "3.9-flower.h"

class Gift
{
 public:
  Gift(Book book);
  Gift(Flower flower);
  void print() const;
 private:
  Book book_;
  Flower flower_;
};

#endif
