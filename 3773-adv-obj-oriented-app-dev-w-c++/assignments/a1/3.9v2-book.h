/**
 * COMP 3773 - Assignment 1 - Exercise 3.9 (v2, not for grading)
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
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
