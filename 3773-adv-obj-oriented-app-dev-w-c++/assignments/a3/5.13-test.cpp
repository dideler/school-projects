/**
 * COMP 3773 - Assignment 3 - Exercise 5.13
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Simple tests for the Sort class and its derived classes.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "5.13-sort.h"
#include "5.13-mergesort.h"
#include "5.13-quicksort.h"
#include <algorithm> // std::shuffle
#include <chrono> // std::chrono::system_clock for random seed
#include <iostream>
#include <random> // std::default_random_engine
#include <vector>
using namespace std;

int main()
{
  vector<double> list1 = {3, 5, 1, 2, 4};
  vector<double> list2 = list1;

  cout << "Sorting array of " << list1.size() << " elements: ";
  for (auto &e : list1) cout << e << " ";
  cout << endl;

  Sort *mergesort = new MergeSort();
  Sort *quicksort = new QuickSort();
  mergesort->timedSort(list1);
  quicksort->timedSort(list2);

  cout << "Mergesort: ";
  for (auto &e : list1) cout << e << " ";
  cout << "\nQuicksort: ";
  for (auto &e : list2) cout << e << " ";
  cout << endl;

  list1.clear();
  list2.clear();

  int size = 10000000;
  list1.reserve(size); // Increase capacity now to avoid on-the-go allocations.
  for (int i = 1; i <= size; ++i) list1.push_back(i);

  // Use a time-based seed and shuffle the list of unique numbers.
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  shuffle(list1.begin(), list1.end(), default_random_engine(seed));

  list2 = list1;
  cout << "Sorting array of " << list1.size() << " elements: " << endl;
  cout << "Mergesort: ~" << mergesort->timedSort(list1) << " sec" << endl;
  cout << "Quicksort: ~" << quicksort->timedSort(list2) << " sec" << endl;
}
