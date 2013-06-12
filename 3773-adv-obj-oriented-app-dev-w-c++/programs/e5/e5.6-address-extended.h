// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 5.6
//
// Interface for class ExtendedAddress
// File: e5.6-address-extended.h

#ifndef E5_6_ADDRESS_EXTENDED_H
#define E5_6_ADDRESS_EXTENDED_H 
#include <string>
using namespace std; // This isn't preferred, it pollutes the namespace.
#include "e5.6-address.h"

namespace e56
{

// Similar to Address class, but also contains a zip.
// Uses a nested pointer to Address for the other attributes.
// Note that this is not a derived class, but inheritance can also be used.
class ExtendedAddress
{
 public:
  // canonical construction
  ExtendedAddress(const string&, const string&, const string&);
  ExtendedAddress(const ExtendedAddress&);
  virtual ~ExtendedAddress();
  ExtendedAddress& operator=(const ExtendedAddress&);
  // queries
  string name() const;
  string address() const;
  string zip() const;
 private:
  Address* rep_; // TODO: is a class declaration not needed?
  string zip_;
};

} // namespace e56

#endif
