/**
 * COMP 3773 - Assignment 2 - Exercise 4.4 using namespaces
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>

namespace item {

class Book
{
 public:
  Book();
  Book(std::string name, double price);
  std::string name() const;
  double price() const;
 private:
  std::string name_;
  double price_;
};

} // namespace item

#endif
