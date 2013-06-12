
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.2.functionfactory.h
  #ifndef EX6_2_FUNCTIONFACTORY_H
  #define EX6_2_FUNCTIONFACTORY_H
  #include <string>
#include "ex6.2.function.h"
  class FunctionFactory {
  public:
    virtual Function* createFunction(const string&) const = 0;
    static FunctionFactory* getFactory(const string&);
    virtual ~FunctionFactory();
  };
  #endif
