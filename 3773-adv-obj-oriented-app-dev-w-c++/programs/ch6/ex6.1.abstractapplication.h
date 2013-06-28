// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.1.abstractapplication.h

#ifndef EX6_1_ABSTRACTAPPLICATION_H
#define EX6_1_ABSTRACTAPPLICATION_H

class AbstractFileOps;
class AbstractApplication // Abstract Factory
{
 public:
  virtual AbstractFileOps* factoryMethod() const = 0;
  long lines() const;  // template method
//void clearCache(); // another template method
  virtual ~AbstractApplication();
};

#endif
