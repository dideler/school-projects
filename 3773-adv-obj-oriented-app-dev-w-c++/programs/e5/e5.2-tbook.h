// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File e5.2-tbook.h
//
// Exercise 5.2
// Interface for class TextBook

#ifndef E5_2_TBOOK_H	
#define E5_2_TBOOK_H  
#include <string>
#include "e5.2-book.h"  

class TextBook : public Book
{
 public:
  TextBook(const string&, int);
  virtual void info() const;
  int get() const;
 private:
  int course_;
};

#endif
