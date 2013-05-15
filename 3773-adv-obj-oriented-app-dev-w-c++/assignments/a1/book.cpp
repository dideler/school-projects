/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#include <iomanip>
#include "book.h"

Book::Book(string name, double price) : Item(name, price) {}

// Printing the price uses fixed-point notation and 2 decimal places precision.
void Book::print(ostream &out) const
{
  out << "Book Name: " << name_ << "\nPrice: $" << std::fixed << std::setprecision(2) << price_;
}
