/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation for the Encryption2Factory concrete class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "6.3-encryption2_factory.h"

Encryption2Factory::~Encryption2Factory() {}

Encryption2Product* Encryption2Factory::createProduct() const
{
  return new Encryption2Product();
}
