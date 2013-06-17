/**
 * COMP 3773 - Assignment 3 - Exercise 5.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation for a queue with its elements stored in array.
 * Uses namespaces and exception handling.
 *
 * This implementation uses a circular array. This makes the queue more space
 * efficient but increases the running time. We keep track of the positions of
 * the front and back elements and wraparound whenever either gets to the end
 * of the array. Another (less desirable) option is to shift all elements to
 * the front of the array whenever you pop the queue.
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "5.11-queue.h"

#include <algorithm>
using std::copy;

namespace queue {

Queue::Queue(int size)
{
  front_ = 0;
  back_ = -1;
  max_size_ = size;
  current_size_ = 0;
  queue_ = new int[size];
}

Queue::Queue(const Queue &other)
{
  front_ = other.front_;
  back_ = other.back_;
  max_size_ = other.max_size_;
  current_size_ = other.current_size_;
  queue_ = new int[max_size_];
  copy(other.queue_, other.queue_ + max_size_, queue_);
}

Queue& Queue::operator=(const Queue &other)
{
  if (this != &other) // Check if it's not self-assignment.
  {
    if (max_size_ != other.max_size_) // Adjust the size if needed.
    {
      delete [] queue_;
      queue_ = new int[other.max_size_];
    }

    // Copy resources.
    front_ = other.front_;
    back_ = other.back_;
    max_size_ = other.max_size_;
    current_size_ = other.current_size_;
    copy(other.queue_, other.queue_ + max_size_, queue_);
  }
  return *this;
}

Queue::~Queue() { delete [] queue_; }

int Queue::size() const { return current_size_; }

// Another way to check is if back == front-1.
bool Queue::empty() const { return current_size_ == 0; }

bool Queue::full() const { return current_size_ == max_size_; }

int Queue::front() const { return queue_[front_]; }

int Queue::back() const { return queue_[back_]; }

void Queue::push(const int &element) throw(logic_error)
{
  if (full()) throw logic_error("Queue is full");
  if (++back_ == max_size_) back_ = 0; // Wrap around.
  queue_[back_] = element;
  ++current_size_;
}

void Queue::pop() throw(logic_error)
{
  if (empty()) throw logic_error("Queue is empty");
  queue_[front_] = 0; // Don't do this in production code. Instead, avoid
                      // the write and throw an exception when trying to
                      // access an element in an "empty" queue.
  if (++front_ == max_size_) front_ = 0; // Wrap around.
  --current_size_;
}

} // namespace queue
