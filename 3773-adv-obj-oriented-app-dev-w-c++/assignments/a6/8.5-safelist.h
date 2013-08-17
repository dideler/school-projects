/**
 * COMP 3773 - Assignment 6 - Exercise 8.5
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Template class SafeList which is derived from std::list and uses exception
 * handling. Definitions are included in the header to simplify linking.
 *
 * Many of the operations below, such as push_front, push_back, and insert,
 * were overridden to provide unnecessary exception handling. Previously,
 * providing an unrelated element type would result in a compilation error,
 * which is probably preferred by the client. In other words, these specific
 * operations didn't _need_ exception handling to be added for safety, since
 * the error would be caught at compile time.
 *
 * Ideas for improvements:
 * - composition instead of inheritance (but exercise requires inheritance)
 * - adapter design pattern for more decoupling (but more overhead)
 * - use more specific exceptions (maybe even custom exceptions)
 *
 * AFAIK, if I override one variation of an overloaded operation, I need to
 * override all variations (even if they don't need exception handling).
 * Otherwise the client code will always call the child class operations,
 * which fails if they do not exist yet.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date August 2013
 * @version 1.1
 */

#ifndef SAFELIST_H_
#define SAFELIST_H_

#include <list>
#include <stdexcept>
using std::list;
using std::domain_error;

template <typename T>
class SafeList : public list<T>
{
 public:

  // Base class constructor implicitly called if no args.

  // Returns a reference to the first element if container is not empty.
  T& front() throw(domain_error)
  {
    if (this->empty())
      throw domain_error("Cannot access first element when container is empty");
    else
      return list<T>::front();
  }

  // Returns a const reference to the first element if container is not empty.
  const T& front() const throw(domain_error)
  {
    if (this->empty())
      throw domain_error("Cannot access first element when container is empty");
    else
      return list<T>::front();
  }

  // Returns a reference to the last element if container is not empty.
  T& back() throw(domain_error)
  {
    if (this->empty())
      throw domain_error("Cannot access last element when container is empty");
    else
      return list<T>::back();
  }

  // Returns a const reference to the last element if container is not empty.
  const T& back() const throw(domain_error)
  {
    if (this->empty())
      throw domain_error("Cannot access last element when container is empty");
    else
      return list<T>::back();
  }

  // Assigns n new elements of value val to the container.
  // Replaces its current contents and resizes the container.
  void assign(int n, const T &val) throw(domain_error)
  {
    if (n < 0) throw domain_error("New size for assignment cannot be negative");
    list<T>::assign(n, val);
  }

  // Assigns new contents in range [first, last) to the container.
  // Replaces its current contents and resizes the container.
  template <typename InputIterator>
  void assign(InputIterator first, InputIterator last)
  {
    list<T>::assign(first, last);
  }
  
  // Assigns new contents in range [first, last) to the container.
  // Replaces its current contents and resizes the container.
  // In addition, it also checks if the specified range is "valid".
  //
  // I only provide a range check for this operation as an example.
  // I don't provide it for every operation that accepts a range because it's
  // messy (in addition to the range, you have to pass an iterator to the end),
  // and because the range check is not safe (you cannot really check if a
  // range is valid, see isValidRange for more info).
  template <typename InputIterator>
  void assign(InputIterator first, InputIterator last, InputIterator end)
      throw(domain_error)
  {
    if (isValidRange(first, last, end))
      list<T>::assign(first, last);
    else
      throw domain_error("Invalid range");
  }

  // Throws exception when element being inserted is of a different type.
  template <typename OtherType>
  void push_front(const OtherType &val) throw(domain_error)
  {
    throw domain_error("Cannot push element of unrelated type");
  }

  // Insert element at beginning.
  void push_front(const T &val) { list<T>::push_front(val); }
 
  // Throws exception when element being inserted is of a different type.
  template <typename OtherType>
  void push_back(const OtherType &val) throw(domain_error)
  {
    throw domain_error("Cannot push element of unrelated type");
  }

  // Add element at the end.
  void push_back(const T &val) { list<T>::push_back(val); }

  // Delete first element.
  void pop_front() throw(domain_error)
  {
    if (this->empty())
      throw domain_error("Cannot pop front when container is empty");
    else
      list<T>::pop_front();
  }

  // Delete last element.
  void pop_back() throw(domain_error)
  {
    if (this->empty())
      throw domain_error("Cannot pop back when container is empty");
    else
      list<T>::pop_back();
  }

  // Throws an exception if you try to insert an element of a different type.
  template <typename Iterator, typename OtherType>
  Iterator insert(Iterator position, const OtherType &val) throw(domain_error)
  {
    throw domain_error("Cannot insert element of unrelated type");
  }

  // Insert a single element before the specified position.
  template <typename Iterator>
  Iterator insert(Iterator position, const T &val)
  {
    return list<T>::insert(position, val);
  }

  // Throws an exception if you try to insert an element of a different type.
  template <typename Iterator, typename OtherType>
  void insert(Iterator position, int n, const OtherType &val)
      throw(domain_error)
  {
    throw domain_error("Cannot insert element of unrelated type");
  }

  // Insert n elements before the specified position.
  template <typename Iterator>
  void insert(Iterator position, int n, const T &val) throw(domain_error)
  {
    if (n < 0)
      throw domain_error("Cannot insert a negative amount of elements");
    else
      list<T>::insert(position, n, val);
  }

  // Insert copies of the elements in the range [first, last) at position.
  template <typename Iterator, typename InputIterator>
  void insert(Iterator position, InputIterator first, InputIterator last)
  {
    list<T>::insert(position, first, last);
  }

  // Erase element at position.
  template <typename Iterator>
  Iterator erase(Iterator position)
  {
    if (this->empty()) return this->begin(); // Prevents invalid pointer crash.
    return list<T>::erase(position);
  }
 
  // Erase elements in range [first, last).
  // Throws exception if invalid range given.
  template <typename Iterator>
  Iterator erase(Iterator first, Iterator last)
  {
    if (this->empty()) return this->begin();
    return list<T>::erase(first, last);
  }

  // Resizes the container so that it contains n elements.
  // If val is specified, the new elements (if n is greater than the current
  // container size) are initialized as copies of val, otherwise the object's
  // default constructor is used.
  void resize(int n, T val = T()) throw(domain_error)
  {
    if (n < 0) throw domain_error("New size for resize cannot be negative");
    else list<T>::resize(n, val);
  }

 private:
  
  // A "valid" range is when first is not in a position behind last.
  // Note that it's actually impossible to check if a range is valid
  // (see http://goo.gl/QyA4hP) but this is Good Enough for our purposes.
  template <typename Iterator>
  bool isValidRange(Iterator first, const Iterator last, const Iterator end)
  {
    for (; first != end; ++first) // Safe to advance first, it's a copy.
      if (first == last) return true;
    return false;
  }
};

#endif
