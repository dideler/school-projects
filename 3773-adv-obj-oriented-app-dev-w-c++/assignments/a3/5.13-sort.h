/**
 * COMP 3773 - Assignment 3 - Exercise 5.13
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface for the Sort class.
 * Based on example 5.4 in the above mentioned book.
 * 
 * Uses the template method design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef SORT_H_
#define SORT_H_

#include <vector>
using std::vector;

// An abstract (base) class for benchmarking sorting algorithms.
class Sort
{
 public:
  virtual ~Sort();
  double timedSort(vector<double>&) const; // Template method.
 protected:
  virtual void sort(vector<double>&) const = 0; // Primitive operation.
};

#endif
