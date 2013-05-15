/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#ifndef BOOK_H_
#define BOOK_H_

#include "item.h"

class Book : public Item
{
 public:
  Book(string name, double price);
  virtual void print(ostream &out) const;
};

#endif
