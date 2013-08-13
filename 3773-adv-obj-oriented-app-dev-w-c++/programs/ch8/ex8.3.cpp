// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8-3

#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

/*
// Push back even numbers.
void filterIn(int i)
{
  if (i % 2 == 0) v.push_back(i);
}
*/

// Output numbers divisible by 6.
void filterOut(int j)
{
  if (j % 6 == 0) cout << j << endl;
}

class FilterVector
{
 public:
  void operator()(int i) { if (i % 2 == 0) v_.push_back(i); }
  vector<int>::iterator begin() { return v_.begin(); }
  vector<int>::iterator end() { return v_.end(); }
 private:
  vector<int> v_;
};

int main()
{
  istream_iterator<int> in(cin);
  istream_iterator<int> eof;
  
  //for_each(in, eof, filterIn);  // read filtered data
  //for_each(v.begin(), v.end(), filterOut); // write filtered data
  
  FilterVector fv;
  fv = for_each(in, eof, fv);  // read filtered data
  for_each(fv.begin(), fv.end(), filterOut);
}
