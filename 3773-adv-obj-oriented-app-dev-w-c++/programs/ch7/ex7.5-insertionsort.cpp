// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//
// A generic algorithm (made from template functions) that operates on a
// generic container (made from template class).

#include <iostream>
using namespace std;

#include "ex7.4-array.cpp"
using namespace ARRAY_NAMESPACE;

template <typename T> // T is a model of LessThan Comparable & Default Constructible 
void insertionSort(Array<T>& array)
{
  int i;
  T key, comp;
  for (int j = 1; j < array.size(); j++)
  {
    key = array[j];
    i = j - 1;
    comp = array[i];
    while (i >= 0 && key <= comp)
    {
      array[i+1] = comp;
      i--;
      if (i >= 0) comp = array[i];
    }
    array[i+1] = key;
  }
}

template <typename T> // T is a model of Default Constructible
void output(const Array<T>& array)
{
  for (int j = 0; j < array.size(); ++j) cout << array[j] << " ";
  cout << endl;
}

template <typename T> // T is a model of Default Constructible
void input(Array<T>& array, const string prompt)
{
  cout << prompt;
  for (int j = 0; j < array.size(); ++j) cin >> array[j];
}
