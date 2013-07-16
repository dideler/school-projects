/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation for the concrete encryption1 factory class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "6.3-encryption1_factory.h"

Encryption1Factory::~Encryption1Factory() {}

Encryption1Product* Encryption1Factory::createProduct() const
{
  return new Encryption1Product();
}
