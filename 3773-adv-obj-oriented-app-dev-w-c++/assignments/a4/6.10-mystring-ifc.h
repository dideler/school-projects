/**
 * COMP 3773 - Assignment 4 - Exercise 6.10 (using modified code from 6.9)
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Abstract interface for several string operations, which will be adopted
 * using std::string.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#ifndef MYSTRING_IFC_H_
#define MYSTRING_IFC_H_

#include <stdexcept>

namespace MyString
{

class StringIfc // The new interface which the client will use.
{
 public:
  // Returns position of char, or -1 if not found.
  virtual int strpos(char) const = 0;

  // Returns length of the current string.
  virtual int strlen() const = 0; 

  // Returns character at position i or throws exception if out of bounds.
  virtual char at(int) const throw(std::domain_error) = 0;
};

} // namespace MyString

#endif
