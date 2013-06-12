// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex5.5.store.cpp
//
// Example 5.5
// Implementation of class Store

#include "ex5.5.store.h"

// implementation of the template method
double Store::getBillableAmount (int units) const
{
  return units * pricePerUnit_ + getTaxAmount(units);
}

Store::Store(double p) : pricePerUnit_(p) {}

Store::~Store() {}

double Store::getPricePerUnit() const { return pricePerUnit_; }

void Store::setPricePerUnit(double d) { pricePerUnit_ = d; }
