// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File e5.2-book.h
//
// Exercise 5.2
// Interface for class Book

#ifndef E5_2_BOOK_H	
#define E5_2_BOOK_H  
#include <string>
using namespace std;

class Book // abstract base class
{
 public:
  Book(const string&);
  virtual ~Book();
  virtual void info() const = 0; // pure virtual function
  string get() const;
 private:
  string name_;
};
#endif
