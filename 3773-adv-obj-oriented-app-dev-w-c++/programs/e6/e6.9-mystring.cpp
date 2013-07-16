// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 6-9
// File: e6.9-mystring.cpp
//
// Implementation of MyString::string_ifc using a class adapter

#include "e6.9-mystring.h"
#include <stdexcept>
#include <string>

namespace MyString
{

string::string(const char* c) : rep_(std::string(c)) {} // rep_(c) should work?

string::string(const std::string& s) : rep_(s) {}

string::string(const string& s) { rep_ = s.rep_; }

string& MyString::string::operator=(const string& s)
{
  if (this != &s) std::string::operator=(s);
  return *this;
}

string::~string() {}

int string::strpos(char c) const
{ 
  std::string::size_type s = rep_.find_first_of(c);
  if (s == std::string::npos) return -1;
  return static_cast<int>(s);
}

int string::strlen() const { return rep_.length(); }

char string::at(int i) const throw(std::domain_error)
{
  if (i < 0 || i >= static_cast<int>(string::strlen())) // doesn't need cast?
    throw std::domain_error("illegal index in at");
  return rep_[i];
}

// Helpers - do not belong to the class but have access to its privates.

// return s2 inserted to s1
string insert(const string& s1, int loc, const string& s2)
    throw(std::domain_error)
{
  if (loc < 0 || loc > static_cast<int>(s2.strlen())) // doesn't need cast?
    throw std::domain_error("incorrect index in insert");
  std::string temp(s1.rep_);  // local copy of s1
  temp.insert(loc, s2.rep_); // FIXME incorrect number of args?
  return string(temp);
}

// return and modifies s1 
string& insert(string& s1, int loc, const string& s2) throw(std::domain_error)
{
  if (loc < 0 || loc > static_cast<int>(s2.strlen())) // FIXME really cast?
    throw std::domain_error("incorrect index in insert");
  std::string temp(s1.rep_);  // local copy of s1
  temp.insert(loc, s2.rep_);
  s1.rep_ = temp;
  return s1;
}

// return s with length characters removed, starting from pos
string remove(const string& s, int pos, int length) throw(std::domain_error)
{
  if (pos < 0 || pos > static_cast<int>(s.strlen()) || length < 0 ||
      pos + length > static_cast<int>(s.strlen())) // FIXME cast?
    throw std::domain_error("incorrect index in remove");
  std::string temp(s.rep_);
  temp.erase(pos, length);
  return string(temp);
}

// return and modify s with length characters removed, starting from pos       
string& remove(string& s, int pos, int length) throw(std::domain_error)
{
  if (pos < 0 || pos > static_cast<int>(s.strlen()) || length < 0 ||
      pos + length > static_cast<int>(s.strlen())) // FIXME cast?
    throw std::domain_error("incorrect index in remove");
  s.rep_.erase(pos, length);
  return s;
}

} // namespace MyString
