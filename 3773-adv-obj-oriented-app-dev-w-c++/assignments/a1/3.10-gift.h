/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * 
 * Rule of three [1] states that if one of
 * {destructor, copy constructor, copy assignment operator}
 * is defined, all three should be explicitly defined.
 * This example works fine with the compiler-generated copy assignment operator,
 * but it was still explicitly added for completeness.
 * [1]: http://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
 */

#ifndef GIFT_H_
#define GIFT_H_

#include "3.10-book.h"
#include "3.10-flower.h"

class Gift
{
 public:
  enum GiftType { BOOK, FLOWER };
  explicit Gift(Book book); // Constructor 1
  explicit Gift(Flower flower); // Constructor 2
  Gift(const Gift &other); // Copy constructor
  Gift& operator=(const Gift &other); // Copy assignment
  ~Gift(); // Destructor
  void print() const; // Prints the gift's info
 private:
  // Note that it's best to avoid raw pointers now that smart pointers exist.
  // But I'm using raw pointers since it's expected for the assignment.
  Book *book_;
  Flower *flower_;
  GiftType type_;
};

#endif
