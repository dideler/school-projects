/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface for the abstract factory class.
 * Based on example 6.1.
 * 
 * Uses the abstract factory design pattern and template method pattern.
 * The template method uses the factory method to create a specific factory
 * object and then uses it to accomplish its task.
 * If template methods weren't used, the client would create a factory object
 * through an instantiating operation (eg static Factory* createFactory(string))
 * and call the factory method through the factory object.
 *
 * Note that this isn't the only way to implement the (abstract) factory design
 * pattern. There is no single correct way. The pattern basically means that you
 * hide/encapsulate object creation in another dedicated class. This reduces
 * dependencies in your code and makes it easier to maintain and modify.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef ABSTRACT_FACTORY_H_
#define ABSTRACT_FACTORY_H_

#include <string>

class AbstractProduct;
class AbstractFactory
{
 public:
  virtual ~AbstractFactory();
  void encrypt(const std::string &filename) const; // template method
  void decrypt(const std::string &filename) const; // template method
 protected:
  virtual AbstractProduct* createProduct() const = 0; // factory method
};

#endif
