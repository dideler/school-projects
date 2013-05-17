
/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#include "3.10-book.h"

Book::Book() {}

Book::Book(std::string name, double price)
  : name_(name), price_(price) {}

std::string Book::name() const { return name_; }

double Book::price() const { return price_; }
