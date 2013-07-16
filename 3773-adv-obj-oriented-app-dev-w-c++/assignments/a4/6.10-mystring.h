/**
 * COMP 3773 - Assignment 4 - Exercise 6.10 (using modified code from 6.9)
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface of MyString::StringIfc using an object adapter.
 * There are four helpers, to insert and remove strings.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#include "6.10-mystring-ifc.h"
#include <stdexcept>
#include <string>

#include <algorithm>

namespace MyString
{

// Note the multiple and private inheritance.
// All public/protected members from std::string become private in this class.
class string : public StringIfc/*, private std::string*/
{
  // Helper functions - friends have access to this class' privates.

  // Returns s1 with s2 inserted at position pos.
  friend string insert(const string& s1, int pos, const string& s2)
    throw(std::domain_error); 

  // Returns and modifies s1 with s2 inserted at position pos.
  friend string& insert(string& s1, int pos, const string& s2)
    throw(std::domain_error);

  // Return s with length characters removed, starting from pos.
  friend string remove(const string& s, int pos, int length)
    throw(std::domain_error); 

  // Return and modify s with length characters removed, starting from pos.
  friend string& remove(string& s, int pos, int length)
    throw(std::domain_error);

 public:
  string(const char*);
  string(const std::string&);
  string(const string&);
  virtual ~string();

  string& operator=(const string&);
  virtual int strpos(char) const;
  virtual int strlen() const;
  virtual char at(int) const throw(std::domain_error); 

 private:
  std::string rep_;
};

} // namespace MyString
