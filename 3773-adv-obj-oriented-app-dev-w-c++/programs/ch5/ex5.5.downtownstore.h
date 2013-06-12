// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex5.5.downtownstore.h
//
// example 5.5
// Interface of class DowntownStore (derived from Store class)

#ifndef DOWNTOWNSTORE_H
#define DOWNTOWNSTORE_H
#include "ex5.5.store.h"

class DowntownStore : public Store // implements Store
{
 public:
  virtual double getTaxAmount(int) const;
  DowntownStore(double, double = 0.07); // default tax rate
  virtual ~DowntownStore();
  double getTaxRate() const;
 private:
  double taxRate_;
};
#endif
