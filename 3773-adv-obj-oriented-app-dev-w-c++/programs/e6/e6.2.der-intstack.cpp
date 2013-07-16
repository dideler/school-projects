// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: e6.2.der-intstack.cpp
//
// Implementation of class DerIntStack

#include "e6.2.der-intstack.h"

DerIntStack::DerIntStack(int i) : IntStack(i) {}

DerIntStack::~DerIntStack() {}

bool DerIntStack::full() const { return top_ == size_ - 1; }

bool DerIntStack::empty() const { return top_ == -1; }
