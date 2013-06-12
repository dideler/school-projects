
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.4
  //File: ex8.4.cpp

#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <utility>

  template<typename Iterator>
  void output(char* p, Iterator first, Iterator last) {
    Iterator aux;
    cout << p << ":";
    for(aux = first; aux != last; ++aux)
      cout << *aux << " ";
    cout << endl;
  }

typedef pair<int, int> IntPair;

  bool same(const IntPair& one, const IntPair& two) {
    return one.first*two.second == one.second*two.first;
  }

  void simplify(IntPair& p) {
    // Use Euclid's algorithm to find gcd of p.first and p.second
    int gcd = abs(p.first);
    int b = abs(p.second);
    while(b) {
      int t = b;
      b = gcd % t;
      gcd = t;
    }
    p.first /= gcd;
    p.second /= gcd;
    if(p.second < 0) {
      p.second = - p.second;
      p.first = - p.first;
    }
  }
#include <list>
ostream& operator<<(ostream& os, const IntPair& ip) {
  os << ip.first << "/" << ip.second << endl;
  return os;
}

int main() {

  list<IntPair> h;
  h.push_front(make_pair(1,2));
  h.push_front(make_pair(4,2));
  h.push_front(make_pair(1,2));
  h.push_front(make_pair(4,2));
  h.push_front(make_pair(6,3));
  h.push_front(make_pair(3,2));
  h.push_front(make_pair(24,4));
  h.push_front(make_pair(12,15));
  h.sort();
  h.unique(same);  // remove same fractions
  for_each(h.begin(), h.end(), simplify); // simplify each fraction
  ostream_iterator<IntPair> o(cout);
  copy(h.begin(), h.end(), o);  // output all remaining fractions
}

