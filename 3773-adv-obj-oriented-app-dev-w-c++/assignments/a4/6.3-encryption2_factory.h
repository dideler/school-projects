/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface for the Encryption2Factory concrete class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef ENCRYPTION2_FACTORY_H_
#define ENCRYPTION2_FACTORY_H_

#include "6.3-factory.h"
#include "6.3-encryption2_product.h"

class Encryption2Factory : public AbstractFactory
{
 public:
  virtual ~Encryption2Factory();
  virtual Encryption2Product* createProduct() const;
};

#endif
