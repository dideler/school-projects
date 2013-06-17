/**
 * COMP 3773 - Assignment 3 - Exercise 5.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface for a queue with its elements stored in array.
 * Uses namespaces and exception handling.
 * 
 * A queue treats elements as "first-in, first-out" (FIFO).
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdexcept>
using std::logic_error;

namespace queue {

class Queue
{
 public:
  explicit Queue(int size = 100); // Default size of 100.
  Queue(const Queue&);
  Queue& operator=(const Queue&);
  ~Queue();

  int size() const; // Returns number of elements in queue.
  bool empty() const; // True if queue has no elements.
  bool full() const; // True if queue has max elements.
  int front() const; // Returns the next element.
  int back() const; // Returns the last element.

  void push(const int&) throw(logic_error); // Insert element.
  void pop() throw(logic_error); // Delete next element.

 private:
  int front_; // Index of first element.
  int back_; // Index of last element.
  int *queue_; // The internal array that holds the elements.
  int max_size_; // The maximum number of elements the queue can fit.
  int current_size_; // The current number of elements in the queue.
};

} // namespace queue

#endif
