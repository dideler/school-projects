/**
 * COMP 3773 - Assignment 1 - Exercise 3.9 (v2, not for grading)
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#include <iomanip>
#include "3.9v2-book.h"

Book::Book() {}

Book::Book(std::string name, double price) : Item(name, price) {}

// Printing the price uses fixed-point notation and 2 decimal places precision.
void Book::print(std::ostream &out) const
{
  out << "Book Name: " << name_
      << "\nPrice: $" << std::fixed << std::setprecision(2) << price_;
}
