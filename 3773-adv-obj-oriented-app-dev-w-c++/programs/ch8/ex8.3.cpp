  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8-3
  // File: ex8.3.cpp
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
#include <vector>

 typedef vector<int>::iterator iterator;
/*
  void filterIn(int i) {  // output only even numbers
    if(i % 2 == 0)
      v.push_back(i);
  }

*/

  void filterOut(int j) {  // output only number divisable by 6
    if(j % 6 == 0)
      cout << j << endl;
  }

  class FilterVector {
  public:
    void operator()(int i) { if(i % 2 == 0) v_.push_back(i);}
    iterator begin() { return v_.begin(); }
    iterator end() { return v_.end(); }
  private:
    vector<int> v_;
  };

int main() {

  istream_iterator<int> i(cin);
  istream_iterator<int> eof;
/*
  for_each(i, eof, filterIn);  // read filtered data
  for_each(v.begin(), v.end(), filterOut); // write filtered data
*/
  FilterVector f;
  f = for_each(i, eof, f);  // read filtered data
  for_each(f.begin(), f.end(), filterOut);
}

