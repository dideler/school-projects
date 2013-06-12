// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: e5.6-address.cpp
//
// Exercise 5.6
// Implementation for class Address

#include "e5.6-address.h"

namespace e56
{

Address::Address(const string& n, const string& a) : name_(n), address_(a) {}

string Address::name() const { return name_; }

string Address::address() const { return address_; }

} // namespace e56
