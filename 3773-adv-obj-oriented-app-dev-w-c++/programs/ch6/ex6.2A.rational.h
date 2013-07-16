// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.A.rational.h

#ifndef EX6_2_RATIONALA_H
#define EX6_2_RATIONALA_H

#include <string>

class Rational : public Function
{
 public:
  virtual void display();
 protected:
  Rational(std::string);
 private:
  int* nomCoefficients_;
  int nomDegree_;
  int* denCoefficients_;
  int denDegree;
};

#endif
