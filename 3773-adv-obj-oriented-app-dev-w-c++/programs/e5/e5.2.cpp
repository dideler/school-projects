// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 5.2
//
// File: e5.2.cpp
// Main program for the simple databooks of books

#include <iostream>
using namespace std;
#include "e5.2-tbook.h"
#include "e5.2-rbook.h"
#include "e5.2-book.h"

void show(const Book* const b[], int size)
{
  for (int i = 0; i < size; ++i) 
    b[i]->info();
}

int main()
{
  const int SIZE = 2;
  Book* books[SIZE];
  books[0] = new TextBook("OOPS", 3773); // course is an int
  books[1] = new ReferenceBook("Relativity Theory", 'P'); // subject is a char
  show(books, SIZE);
  // RTTI (run time type identification)
  // Downcast Book to ReferenceBook if possible.
  // RTTI should be avoided whenever possible, it's an indication of bad design.
  // Instead, use polymorphic functions defined in the base class, or a factory.
  for (int i = 0; i < SIZE; ++i) 
    if (ReferenceBook* p = dynamic_cast<ReferenceBook*>(books[i]))  // returns 0 if cannot convert
      cout << "subject = " << p->get() << endl;
}
