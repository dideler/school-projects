// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex5.5.neighborhoodstore.h
//
// Example 5.5
// Interface of class NeighborhoodStore 

#ifndef NEIGHBORHOODSTORE_h
#define NEIGHBORHOODSTORE_H
#include "ex5.5.store.h"

// Derived class of the abstract base class, Store.
class NeighborhoodStore : public Store
{
 public:
  virtual double getTaxAmount(int) const;
  NeighborhoodStore(double, double = 0.01); // default tax rate
  virtual ~NeighborhoodStore();
  double getTaxRate() const;
 private:
  double taxRate_;
};

#endif
