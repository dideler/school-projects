  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Example 9.1
  // File: ex9.1.cpp
#include <iostream>
using namespace std;
int main() {
  int sum = 0;
  int i;
  bool ok = true;
  cout << "Enter integer values, to terminate enter ^D or a non-integer" << endl;
  while(1) {
    cin >> i;
    if(cin.eof())
      break;
    if(cin.fail()) {
      ok = false;
      break;
    }
    sum += i;
  }
  cout << (ok ? "" : "non-integer value encountered\n") <<
    " sum = " << sum << endl;
}

