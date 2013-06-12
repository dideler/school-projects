// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex5.5.downtownstore.cpp
//
// Implementation of the abstract operations.
// Example 5.5
// Implementation of DowntownStore class

#include "ex5.5.downtownstore.h"

double DowntownStore::getTaxAmount(int units) const { return units * taxRate_; }

DowntownStore::DowntownStore(double pricePerUnit, double taxRate)
    : Store(pricePerUnit), taxRate_(taxRate) {}

DowntownStore::~DowntownStore() {}

double DowntownStore::getTaxRate() const { return taxRate_; }
