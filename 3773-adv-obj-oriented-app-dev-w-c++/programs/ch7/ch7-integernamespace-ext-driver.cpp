// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley

#include <iostream>
using namespace std;

#include "ch7-integernamespace.h"
#include "ch7-integernamespace-ext.h"
using namespace IntegerNamespace;

int main()
{
 Integer i;
 Integer j(4);
 ++i;
 cout << i << " == 1 " << endl;
 j += 3;
 cout << j << " == 7" << endl;
 cout << "enter int value: ";
 cin >> j;
 cout << endl;
 i += j;
 cout << i << endl << j << endl; 
 cout << i + j << endl;
 cout << i + 2 << endl;
 cout << 3 + j << endl;
 cout << j << j++ << endl;
 cout << "i == j " << (i == j) << endl;
}
