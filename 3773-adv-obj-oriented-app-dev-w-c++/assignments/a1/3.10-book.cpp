/**
 * COMP 3773 - Assignment 1 - Exercise 3.10
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#include "3.10-book.h"

Book::Book() {}

Book::Book(std::string name, double price)
  : name_(name), price_(price) {}

std::string Book::name() const { return name_; }

double Book::price() const { return price_; }
