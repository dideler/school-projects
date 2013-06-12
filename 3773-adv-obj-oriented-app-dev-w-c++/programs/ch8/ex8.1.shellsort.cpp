  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
 // File: ex8.1.shellsort.cpp
  #include <iterator>
  template <typename Iterator>
  // Iterator is a model of Random Access Iterator
  void shellSort(Iterator first, Iterator last) {
    typedef typename iterator_traits<Iterator>::difference_type Distance;
    const Distance size = last - first;
    for(Distance gap = size/2; gap > 0; gap /= 2)
     for(Distance i = gap; i < size; ++i)
      for(Distance j = i - gap; j >= 0; j -= gap)
        if(*(first+j+gap) < *(first+j)) {
          typename iterator_traits<Iterator>::value_type temp;
          temp = *(first + j);
          *(first+j) = *(first + j + gap);
          *(first+j+gap) = temp;
      }
   }
