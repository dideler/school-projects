// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.3.attributedstudent.h

#ifndef EX6_3_ATTRIBUTEDSTUDENT_H
#define EX6_3_ATTRIBUTEDSTUDENT_H

#include "ex6.3.student.h"

class AttributedStudent : public AttributedObject, public Student
{
 public:
  AttributedStudent(long);
  virtual ~AttributedStudent();
  //...
};

#endif
