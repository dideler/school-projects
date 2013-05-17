/**
 * COMP 3773 - Assignment 1 - Exercise 3.10
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Rule of three [1] states that if one of
 * {destructor, copy constructor, copy assignment operator}
 * is defined, all three should be explicitly defined.
 * This example works fine with the compiler-generated copy assignment operator,
 * but it was still explicitly added for completeness.
 * [1]: http://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#ifndef GIFT_H_
#define GIFT_H_

#include "3.10-book.h"
#include "3.10-flower.h"

class Gift
{
 public:
  enum GiftType { BOOK, FLOWER };
  explicit Gift(Book book);
  explicit Gift(Flower flower);
  Gift(const Gift &other);
  Gift& operator=(const Gift &other);
  ~Gift();
  void print() const;
 private:
  // Note that it's best to avoid raw pointers now that smart pointers exist.
  // But I'm using raw pointers since it's expected for the assignment.
  Book *book_;
  Flower *flower_;
  GiftType type_;
};

#endif
