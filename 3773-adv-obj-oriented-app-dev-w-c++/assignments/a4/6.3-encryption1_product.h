/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface for the concrete encryption1 product class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef ENCRYPTION1_PRODUCT_H_
#define ENCRYPTION1_PRODUCT_H_

#include "6.3-product.h"
#include <string>

// Encryption algorithm: an integer N is added to the ordinal (aka ASCII) value
// of each character. The user supplies the encryption code N at runtime.
//
// The filename and key are not kept as data members intentionally.
// The user has to provide this info at runtime for all encryption & decryption.
class Encryption1Product : public AbstractProduct
{
 public:
  virtual ~Encryption1Product();

  // Encrypts the given file and prints the cipher text.
  virtual void encrypt(const std::string &filename) const;

  // Decrypts the given file and prints the plain text.
  virtual void decrypt(const std::string &filename) const;
};

#endif
