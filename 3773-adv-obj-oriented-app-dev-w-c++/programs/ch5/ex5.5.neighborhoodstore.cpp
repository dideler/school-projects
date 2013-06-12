// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex5.5.neighborhoodstore.cpp
//
// Example 5.5
// implementation of class NeighborhoodStore

#include "ex5.5.neighborhoodstore.h"

double NeighborhoodStore::getTaxAmount(int units) const
{
  return units * taxRate_;
}

NeighborhoodStore::NeighborhoodStore(double pricePerUnit, double taxRate)
    : Store(pricePerUnit), taxRate_(taxRate) {}

NeighborhoodStore::~NeighborhoodStore() {}

double NeighborhoodStore::getTaxRate() const { return taxRate_; }
