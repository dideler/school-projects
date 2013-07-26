// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley

#include "ex7.5-insertionsort.cpp"

int main()
{
  Array<int> x(5);
  input(x, "Enter 5 integer values: ");
  insertionSort(x);
  output(x);
}
