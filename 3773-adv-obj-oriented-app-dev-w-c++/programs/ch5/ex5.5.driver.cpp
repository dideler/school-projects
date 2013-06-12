// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Simple tester program for Example 5.5

#include <iostream>
using namespace std;
#include "ex5.5.downtownstore.h"
#include "ex5.5.neighborhoodstore.h"

int main()
{
  const int UNITS = 25;
  const double PRICE_PER_UNIT = 10;
  Store* s1 = new DowntownStore(PRICE_PER_UNIT); // default tax rate
  Store* s2 = new NeighborhoodStore(PRICE_PER_UNIT);  // default tax rate
  cout << "for " << UNITS << " units, pay " << endl;
  cout << "downtown: $" << s1->getBillableAmount(UNITS) << endl;
  cout << "neighborhood: $" << s2->getBillableAmount(UNITS) << endl; 
}
