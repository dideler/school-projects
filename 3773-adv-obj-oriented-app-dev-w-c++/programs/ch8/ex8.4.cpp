// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.4

#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <list>
using namespace std;

typedef pair<int, int> IntPair;

template<typename Iterator>
void output(Iterator first, Iterator last)
{
  for (Iterator aux = first; aux != last; ++aux)
    cout << *aux << endl;
}

bool same(const IntPair &one, const IntPair &two)
{
  return one.first * two.second == one.second * two.first;
}

void simplify(IntPair &p)
{
  // Use Euclid's algorithm to find gcd of p.first and p.second
  int gcd = abs(p.first);
  int b = abs(p.second);
  
  while(b)
  {
    int t = b;
    b = gcd % t;
    gcd = t;
  }

  p.first /= gcd;
  p.second /= gcd;
  
  if (p.second < 0)
  {
    p.second = -p.second;
    p.first = -p.first;
  }
}

// Output an IntPair.
ostream& operator<<(ostream& os, const IntPair& ip)
{
  os << ip.first << " / " << ip.second;
  return os;
}

int main()
{
  list<IntPair> h;
  h.push_front(make_pair(1, 2));
  h.push_front(make_pair(4, 2));
  h.push_front(make_pair(1, 2));
  h.push_front(make_pair(4, 2));
  h.push_front(make_pair(6, 3));
  h.push_front(make_pair(3, 2));
  h.push_front(make_pair(24, 4));
  h.push_front(make_pair(12, 15));
  h.sort();
  h.unique(same); // Remove duplicate fractions.
  for_each(h.begin(), h.end(), simplify); // Simplify each fraction.
  ostream_iterator<IntPair> out(cout);
  //copy(h.begin(), h.end(), out); // Output all remaining fractions.
  output(h.begin(), h.end());
}
