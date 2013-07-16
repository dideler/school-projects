/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation of the abstract factory class.
 * Based on example 6.1.
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "6.3-factory.h"
#include "6.3-product.h"
#include <string>
using std::string;

AbstractFactory::~AbstractFactory() {}

void AbstractFactory::encrypt(const string &filename) const
{
  AbstractProduct* product = createProduct();
  product->encrypt(filename);
}

void AbstractFactory::decrypt(const string &filename) const
{
  AbstractProduct* product = createProduct();
  product->decrypt(filename);
}
