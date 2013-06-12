// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: e5.6-address-post.cpp
//
// Exercise 5.6
// Implementation for class PostAddress

#include <string>
#include "e5.6-address-post.h"

namespace e56
{

PostAddress::PostAddress(const string& n, const string& a, const string& z,
                         const string& p)
    : ExtendedAddress(n, a, z), postbox_(p) {}

// PostAddress::~PostAddress() {}

PostAddress::PostAddress(const PostAddress& p)
    : ExtendedAddress(p), postbox_(p.postbox_) {}

PostAddress& PostAddress::operator=(const PostAddress& p)
{
  if (this != &p)
  {
    ExtendedAddress::operator=(p); // DRY - reuse code where possible
    postbox_ = p.postbox_;
  }
  return *this;
}

string PostAddress::postbox() const { return postbox_; }

} // namespace e56
