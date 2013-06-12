
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.2.rationalfactory.cpp
 
  // Implementation for the class RationalFactory
  #include "ex6.2.rationalfactory.h"
  #include "ex6.2.rational.h"
  Rational* RationalFactory::createFunction(const string& s) const{
    return new Rational(s);
  }
  RationalFactory::~RationalFactory() {}
  
