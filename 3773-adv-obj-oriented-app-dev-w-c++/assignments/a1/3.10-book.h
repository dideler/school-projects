/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>

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

#endif
