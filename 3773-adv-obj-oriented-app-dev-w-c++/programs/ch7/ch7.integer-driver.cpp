  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Section 7.3, page 286
#include <iostream>
using namespace std;
#include "ch7.integer.h"

int main() {
  try {
    Integer i(2, 0, 5); // initial value 2; range [0,5]
    Integer j(4, 0, 5);
    i = i + j; // will throw exception
  } catch(std::range_error& e) {
    cout << e.what() << endl;
  }

  return 0;
  }

