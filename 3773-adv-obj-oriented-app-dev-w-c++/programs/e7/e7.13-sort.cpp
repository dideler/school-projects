// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: e7.13-sort.cpp
//
// Function that implements bubble sort for Exercise 7-13

#include "ex7.4.array.cpp"
#include <iostream>
using namespace std;
using namespace ARRAY_NAMESPACE;

template <typename T>
// T is a model of LessThan Comparable and Default Constructible 

void sort(Array<T>& array)
{
  for (int i = 0; i < array.size() - 1; ++i)
  {
    for (int j = array.size(); j > i; --j)
    {
      if (array[j] < array[j-1]) // swap (NOTE: can use std::swap instead)
      {
        T key = array[j-1];
        array[j-1] = array[j];
        array[j] = key;
      }
    }
  }
}

template <typename T>
// T is a model of Default Constructible

void output(const Array<T>& array)
{
  for (int j = 0; j < array.size(); ++j)
    cout << array[j] << " ";
  cout << endl;
}

template <typename T>
// T is a model of Default Constructible

void input(Array<T>& array, const string prompt)
{
  cout << prompt;
  for (int j = 0; j < array.size(); ++j)
    cin >> array[j];
}
