/**
 * COMP 3773 - Assignment 3 - Exercise 5.13
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Interface for the MergeSort class, derived from Sort class.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "5.13-sort.h"
#include <vector>
using std::vector;

class MergeSort : public Sort
{
 public:
  virtual void sort(vector<double>&) const;
 private:
  void mergesort(vector<double>&, vector<double>&, int, int) const;
  void merge(vector<double>&, vector<double>&, int, int, int) const;
};

#endif
