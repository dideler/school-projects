/**
 * COMP 3773 - Assignment 1 - Exercise 3.10
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date May 2013
 * @version 1.0
 */

#include <iostream>
#include <iomanip>
#include "3.10-gift.h"

Gift::Gift(Book book) : book_(new Book(book)), type_(BOOK) {}

Gift::Gift(Flower flower) : flower_(new Flower(flower)), type_(FLOWER) {}

Gift::Gift(const Gift &other) : type_(other.type_)
{
  switch (type_)
  {
    case BOOK:
      book_ = new Book(*(other.book_));
      break;
    case FLOWER:
      flower_ = new Flower(*(other.flower_));
      break;
    default:
      // Could throw an exception here for example.
      break;
  }
}

Gift& Gift::operator=(const Gift &other)
{
  if (this == &other)
    return *this;
  (*book_) = (*other.book_);
  (*flower_) = (*other.flower_);
  type_ = other.type_;
  return *this;
}

Gift::~Gift()
{
  if (type_ == BOOK && book_ != nullptr)
    delete book_;
  if (type_ == FLOWER && flower_ != nullptr)
    delete flower_;
}

void Gift::print() const
{
  switch (type_)
  {
    case BOOK:
      std::cout << "Book name: " << book_->name() << "\n"
        << "Price: $" << std::fixed << std::setprecision(2) << book_->price()
        << std::endl;
      break;
    case FLOWER:
      std::cout << "Flower name: " << flower_->name() << "\n"
        << "Colour: " << flower_->colour() << "\n"
        << "Price: $" << std::fixed << std::setprecision(2) << flower_->price()
        << std::endl;
      break;
    default:
      std::cout << "Unknown gift" << std::endl;
  }
}
