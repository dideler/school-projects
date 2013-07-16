/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface for the abstract product class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef ABSTRACT_PRODUCT_H_
#define ABSTRACT_PRODUCT_H_

#include <string>

class AbstractProduct
{
 public:
  virtual ~AbstractProduct();
  virtual void encrypt(const std::string &filename) const = 0;
  virtual void decrypt(const std::string &filename) const = 0;
 protected:
  void clearBuffer() const; // Clears the cin buffer.
};

#endif
