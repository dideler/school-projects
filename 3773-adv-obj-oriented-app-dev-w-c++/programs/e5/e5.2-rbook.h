// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File e5.2-rbook.h 
//
// Exercise 5.2
// Interface for class TextBook

#ifndef E5_2_RBOOK_H	
#define E5_2_RBOOK_H  
#include <string>
#include "e5.2-book.h"

class ReferenceBook : public Book
{
 public:
  ReferenceBook(const string&, char);
  virtual void info() const;
  char get() const;
 private:
  char subject_;
};

#endif
