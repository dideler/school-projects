// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File e5.2-tbook.cpp
//
// Exercise 5.2
// Implementation for class TextBook

#include <iostream>
using namespace std;
#include "e5.2-tbook.h"

TextBook::TextBook(const string& name, int c) : Book(name), course_(c) {}

// Book's name_ member is private, so it's not inherited.
// So we have to use the query method Book::get().
// If Book::name_ was protected, we could access it from TextBook::name_.
// If Book::name_ was public, we should also be able to access it directly.
void TextBook::info() const
{
  cout << "text book " << Book::get() << ", for course " << course_ << endl;
}

int TextBook::get() const { return course_; }
