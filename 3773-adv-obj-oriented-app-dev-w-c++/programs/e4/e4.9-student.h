// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex4.9.student.h
// Header file with the class definition

#ifndef EX4_9_STUDENT_H
#define EX4_9_STUDENT_H
#include <string>
using namespace std;

namespace e4_9 {
class Student { 
 public:
  Student(const string& = ""); // no-arg constructor needed for array init
  long getId() const;
  string getName() const;
  void setName(const string&);
 private:
  string name_;
  long id_;      
  static long idCounter_;
};  
} // namespace e4_9
#endif
