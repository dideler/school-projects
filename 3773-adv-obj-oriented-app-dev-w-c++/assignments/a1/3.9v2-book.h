/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#ifndef BOOK_H_
#define BOOK_H_

#include "3.9v2-item.h"

class Book : public Item
{
 public:
  Book();
  Book(std::string name, double price);
 private:
  void print(std::ostream &out) const;
};

#endif
