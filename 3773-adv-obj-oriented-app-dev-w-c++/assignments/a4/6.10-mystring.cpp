/**
 * COMP 3773 - Assignment 4 - Exercise 6.10 (using modified code from 6.9)
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation of MyString::string_ifc using an object adapter.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#include "6.10-mystring.h"
#include <stdexcept>
#include <string>

namespace MyString
{

string::string(const char* c) : rep_(c) {}

string::string(const std::string& s) : rep_(s) {}

string::string(const string& s) : rep_(s.rep_) {}

string& MyString::string::operator=(const string& s)
{
  if (this != &s) rep_ = s.rep_;
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
  if (i < 0 || i >= string::strlen())
    throw std::domain_error("Index for at is out of bounds");
  return rep_[i];
}

// Helpers - do not belong to the class but have access to its privates.

// Returns s1 with s2 inserted at position pos.
string insert(const string& s1, int pos, const string& s2)
    throw(std::domain_error)
{
  if (pos < 0 || pos > s1.strlen())
    throw std::domain_error("Index for insert is out of bounds");
  std::string temp(s1.rep_);
  temp.insert(pos, s2.rep_);
  return string(temp);
}

// Returns and modifies s1 with s2 inserted at position pos.
string& insert(string& s1, int pos, const string& s2) throw(std::domain_error)
{
  if (pos < 0 || pos > s1.strlen())
    throw std::domain_error("Index for insert is out of bounds");
  s1.rep_.insert(pos, s2.rep_);
  return s1;
}

// Return s with length characters removed, starting from pos.
string remove(const string& s, int pos, int length) throw(std::domain_error)
{
  if (pos < 0 || pos > s.strlen())
    throw std::domain_error("Index for remove is out of bounds");
  if (length < 0 || pos + length > s.strlen())
    throw std::domain_error("Length for remove is illegal");
  std::string temp(s.rep_);
  temp.erase(pos, length);
  return string(temp);
}

// Return and modify s with length characters removed, starting from pos.
string& remove(string& s, int pos, int length) throw(std::domain_error)
{
  if (pos < 0 || pos > s.strlen())
    throw std::domain_error("Index for remove is out of bounds");
  if (length < 0 || pos + length > s.strlen())
    throw std::domain_error("Length for remove is illegal");
  s.rep_.erase(pos, length);
  return s;
}

} // namespace MyString
