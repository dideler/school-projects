/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <ostream>

// The Item class is a base class for other items such as books and flowers.
class Item
{
 public:
  Item();

  Item(std::string name, double price);

  virtual ~Item();

  std::string name() const;

  double price() const;

 protected:
  // Protected members can only be accessed by member functions and friends of
  // that class, and by member functions and friends of derived classes.

  // Prints the object's attributes.
  // Note that this is a pure virtual method, making this an abstract class.
  // A pure virtual method has no definition in the abstract class, only in
  // derived classes.
  // http://www.cplusplus.com/doc/tutorial/polymorphism/
  virtual void print(std::ostream &out) const = 0;

  std::string name_;

  double price_;

  friend std::ostream &operator<<(std::ostream &out, const Item &item);
};

#endif
