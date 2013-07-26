// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Section 7.3, page 282
//
// Extension of a namespace (by adding more overloaded operators).

#ifndef INTEGERNAMESPACE_EXT_H
#define INTEGERNAMESPACE_EXT_H

#include "ch7-integernamespace.h"  

namespace IntegerNamespace
{
bool operator==(const Integer&, const Integer&);
bool operator!=(const Integer&, const Integer&);
}

#endif
