/**
 * COMP 3773 - Assignment 3 - Exercise 5.13
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation of the Sort class.
 * Based on example 5.4 in the above mentioned book.
 * 
 * Uses the template method design pattern.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "5.13-sort.h"
#include <chrono>
#include <vector>
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::time_point;
using std::chrono::steady_clock; // Best suited for measuring intervals.
using std::vector;

Sort::~Sort() {}

// Returns time in precise seconds.
double Sort::timedSort(vector<double> &list) const
{
  auto start = steady_clock::now();
  sort(list);
  auto end = steady_clock::now();
  return duration_cast<milliseconds>(end-start).count() / 1000.0;
}
