/**
 * COMP 3773 - Assignment 2 - Exercise 4.4 using namespaces
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "4.4-book.h"

namespace item {

Book::Book() {}

Book::Book(std::string name, double price)
  : name_(name), price_(price) {}

std::string Book::name() const { return name_; }

double Book::price() const { return price_; }

} // namespace item
