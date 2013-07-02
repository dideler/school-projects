/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface for the Encryption2Product concrete class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef ENCRYPTION2_PRODUCT_H_
#define ENCRYPTION2_PRODUCT_H_

#include "6.3-product.h"
#include <string>

// Encryption algorithm: the user provides a keyword; an input file is divided
// into blocks equal to the size of the word, and then the i-th character in
// that block is encrypted by adding the ASCII code of the i-th character in
// the keyword. This is a variation of the Vigenère cipher.
//
// The filename and key are not kept as data members intentionally.
// The user has to provide this info at runtime for all encryption & decryption.
class Encryption2Product : public AbstractProduct
{
 public:
  virtual ~Encryption2Product();

  // Encrypts the given file and prints the cipher text.
  virtual void encrypt(const std::string &filename) const;

  // Decrypts the given file and prints the plain text.
  virtual void decrypt(const std::string &filename) const;
};

#endif
