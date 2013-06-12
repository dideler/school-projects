// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File e5.2-book.cpp
//
// Exercise 5.2
// Implementation for class Book

#include "e5.2-book.h"

Book::Book(const string& name) : name_(name) {}

Book::~Book() {} 

string Book::get() const { return name_; }
