// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex2.2.cpp

#include <cmath>  // needed to use sqrt()
#include <iostream>
using namespace std;

// Purpose: Test a prime() function
bool prime(int);  // Declaration, aka prototype.

int main()
{
  int i;
  cout << "Enter an integer value" << endl;

  if (!(cin >> i))
  {
    cerr << "Incorrect integer, aborting" << endl;
    return 1;
  }
  cout << i << " is " << (prime(i) ? "prime" : "not prime") << endl;
}

// Function: prime
// Purpose: checks if n is prime
// Inputs: integer n
// Returns: true if n is prime; otherwise false
// Sample call: if(prime(i)) ...
bool prime(int n) // function definition
{
  if (n < 4) return n >= 1;
  if (n % 2 == 0) return false;

  int divisor;
  double root = sqrt((double) n) + 0.5;
  for (divisor = 3; divisor <= root && n % divisor != 0; divisor += 2);
  return divisor > root;
}
