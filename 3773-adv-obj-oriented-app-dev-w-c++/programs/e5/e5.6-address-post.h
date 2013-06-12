// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: e5.6-address-post.h
//
// Exercise 5.6
// Interface for class PostAddress

#ifndef E5_6_ADDRESS_POST_H
#define E5_6_ADDRESS_POST_H 
#include <string>
#include "e5.6-address-extended.h"

namespace e56
{

class PostAddress : public ExtendedAddress
{
 public:
  PostAddress(const string&, const string&, const string&, const string&);
  PostAddress(const PostAddress&);
  PostAddress& operator=(const PostAddress&);
  string postbox() const;
 private:
  string postbox_;
};

} // namespace e56

#endif
