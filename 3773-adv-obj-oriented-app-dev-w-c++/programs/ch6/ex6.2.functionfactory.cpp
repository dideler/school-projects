
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.2.functionfactory.cpp
  // Implementation for the class FunctionFactory

  #include "ex6.2.functionfactory.h"
  #include "ex6.2.polynomialfactory.h"
  #include "ex6.2.rationalfactory.h"
  #include <string>
  FunctionFactory* FunctionFactory::getFactory(const string& s) {
     string::size_type pos = s.find_first_of('/');
    // if(s represents a polynomial
    if(pos == string::npos)
      return new PolynomialFactory();
    return new RationalFactory();
    // return 0;  // error
  }
  FunctionFactory::~FunctionFactory() {}
  
