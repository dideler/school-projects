// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: e5.6-address.h
//
// Exercise 5.6
// Interface for class Address

#ifndef E5_6_ADDRESS_H
#define E5_6_ADDRESS_H 
#include <string>
using namespace std;

namespace e56
{

class Address
{
 public:
  Address(const string&, const string&);
  string name() const;
  string address() const;
 private:
  string name_;
  string address_;
};

} // namespace e56

#endif
