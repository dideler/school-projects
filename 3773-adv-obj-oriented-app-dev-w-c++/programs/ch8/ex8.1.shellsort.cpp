// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1
//
// Two templated typedefs are used: Distance and Value.
// - The way Distance is typedef'd is only valid inside the function.
// - The way Value is typedef'd is a new feature of C++11, an alias.
//   This method of typedeffing requires a template argument at instantiation.

#include <iterator> // For the helper class iterator_traits.
using std::iterator_traits;

template <typename Iterator> 
using Value = typename iterator_traits<Iterator>::value_type;

// Iterator is a model of Random Access Iterator, which means it can perform
// read, write, multiple pass-throughs, reverse iteration, arbitrary sized steps
template <typename Iterator>
void shellSort(Iterator first, Iterator last)
{
  typedef typename iterator_traits<Iterator>::difference_type Distance;
  const Distance size = last - first;
  for (Distance gap = size / 2; gap > 0; gap /= 2)
  {
    for (Distance i = gap; i < size; ++i)
    {
      for (Distance j = i - gap; j >= 0; j -= gap)
      {
        if (*(first + j + gap) < *(first + j)) // swap
        {
          const Value<Iterator> temp = *(first + j);
          *(first + j) = *(first + j + gap);
          *(first + j + gap) = temp;
        }
      }
    }
  }
}
