/**
 * COMP 3773 - Assignment 1 - Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#ifndef GIFT_H_
#define GIFT_H_

#include "3.9-book.h"
#include "3.9-flower.h"

class Gift
{
 public:
  explicit Gift(Book book);
  explicit Gift(Flower flower);
  void print() const;
 private:
  Book book_;
  Flower flower_;
};

#endif
