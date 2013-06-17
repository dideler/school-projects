/**
 * COMP 3773 - Assignment 3 - Exercise 5.13
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation of the QuickSort class, derived from Sort class.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "5.13-quicksort.h"
#include <utility> // std::swap moved from <algorithm> to <utility> in C++11.
#include <vector>
using std::swap;
using std::vector;

// Public driver method.
void QuickSort::sort(vector<double> &list) const
{
  quicksort(list, 0, list.size() - 1);
}

// Internal method that makes recursive calls.
// 
// In practice, quicksort would be combined with a fast stable sequential
// search, such as insertion sort. Quicksort does not perform well on very
// small arrays (N <= 20), and because quicksort is recursive, small
// arrays occur frequently. Quicksort would switch to insertion sort for
// small arrays -- cutoff point for switching is typically between N=5 and N=20.
void QuickSort::quicksort(vector<double> &list, int left, int right) const
{
  double pivot = median(list, left, right);
  int i = left, j = right;
  
  while (i <= j) // Partition.
  {
    while (list[i] < pivot) i++;
    while (list[j] > pivot) j--;
    if (i <= j) swap(list[i++], list[j--]);
  }

  if (left < j) quicksort(list, left, j);
  if (i < right) quicksort(list, i, right);
}

// Internal method that chooses a pivot using "median-of-three" partitioning.
// Sorts elements so that list[left] <= list[centre] <= list[right].
// Returns the median of left, centre, and right.
double QuickSort::median(vector<double> &list, int left, int right) const
{
  int centre = (left + right) / 2;

  if (list[centre] < list[left]) swap(list[centre], list[left]);
  if (list[right] < list[left]) swap(list[right], list[left]);
  if (list[right] < list[centre]) swap(list[right], list[centre]);

  return list[centre];
}
