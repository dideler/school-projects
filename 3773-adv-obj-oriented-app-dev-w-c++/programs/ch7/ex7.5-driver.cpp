  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File ex7.5.driver.cpp
  #include "ex7.5.insertiosort.cpp"
  int main() {
    Array<int> x(5);
    input(x, "Enter 5 integer values:");
    insertionSort(x);
    output(x);

    return 0;
  }

