/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface for the concrete encryption1 factory class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef ENCRYPTION1_FACTORY_H_
#define ENCRYPTION1_FACTORY_H_

#include "6.3-factory.h"
#include "6.3-encryption1_product.h"

class Encryption1Factory : public AbstractFactory
{
 public:
  //EncryptionAFactory();
  virtual ~Encryption1Factory();
  virtual Encryption1Product* createProduct() const;
};

#endif
