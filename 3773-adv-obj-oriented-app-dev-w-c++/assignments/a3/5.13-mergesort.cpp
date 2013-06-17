/**
 * COMP 3773 - Assignment 3 - Exercise 5.13
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Implementation of the MergeSort class, derived from Sort class.
 * This is an adaption of the mergesort algorithm in the book:
 *  "Data Structures and Algorithm Analysis in Java" by M.A. Weiss
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "5.13-mergesort.h"
#include <vector>
using std::vector;

// Public driver method.
void MergeSort::sort(vector<double> &list) const
{
  int length = list.size();
  vector<double> merge_list(length);
  mergesort(list, merge_list, 0, length-1);
}

// Internal method that makes recursive calls.
void MergeSort::mergesort(vector<double> &list, vector<double> &merge_list,
                          int left, int right) const
{
  if (left < right)
  {
    int centre = (left + right) / 2;
    mergesort(list, merge_list, left, centre);
    mergesort(list, merge_list, centre + 1, right);
    merge(list, merge_list, left, centre + 1, right);
  }
}

// Internal method that merges two sorted halves of a subarray.
void MergeSort::merge(vector<double> &list, vector<double> &merge_list,
                      int left, int right, int right_end) const
{
  int left_end = right - 1;
  int merge_index = left;
  int num_elements = right_end - left + 1;

  // The original list is divided and used as two input arrays.
  // There is also the output list, merge_list in this case.
  // There are three index counters, one for each half of the input array, and
  // one for the output array. The smaller element is copied to the output array
  // and the appropriate counter is advanced. When either counter from the input
  // array is exhausted, the remainder of the non-exhausted input list is copied
  // to the output list.
  while (left <= left_end && right <= right_end)
  {
    if (list[left] <= list[right])
      merge_list[merge_index++] = list[left++];
    else
      merge_list[merge_index++] = list[right++];
  }

  while (left <= left_end) // Copy rest of left half.
    merge_list[merge_index++] = list[left++];

  while (right <= right_end) // Copy rest of right half.
    merge_list[merge_index++] = list[right++];

  // Copy output list to original list.
  for (int i = 0; i < num_elements; ++i, --right_end)
    list[right_end] = merge_list[right_end];
}
