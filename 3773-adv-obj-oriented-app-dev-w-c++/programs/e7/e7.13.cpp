  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 7-13
  // Simple test for a bubble sort
  // File ex7.13.cpp
  #include "e7.13-sort.cpp"
  int main() {
    Array<int> x(5);
    input(x, "Enter 5 integer values:");
    sort(x);
    output(x);
  }

