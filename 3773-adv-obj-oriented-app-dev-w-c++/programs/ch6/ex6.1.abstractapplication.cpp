
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.1.abstractapplication.cpp
  // Implementation for the class AbstractApplication
 #include "ex6.1.abstractapplication.h"
 #include "ex6.1.abstractfile.h"
  long AbstractApplication::lines() const { 
    AbstractFileOps* afo = factoryMethod();
    return afo->lines();
  }
/*
  void AbstractApplication::clearCache() {
    AbstractFileOps* afo = factoryMethod();
    afo->clearCache();
 }
*/
 AbstractApplication::~AbstractApplication() {} 
