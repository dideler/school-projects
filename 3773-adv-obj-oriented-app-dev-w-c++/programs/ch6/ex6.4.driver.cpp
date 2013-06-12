
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4.driver.cpp
  // Exercise 6-4, 1st version    
  // Sample main program
  #include "ex6.4.expression.h"
  int main() {
    Expression two(2);
    Expression four(4);
  
    Expression exp1("+",two, four); // Figure 6.16

    Expression common("+", two, four);
    Expression exp2("*", common, common);  // Figure 6.17

    exp1.print(cout);
    cout << exp1.eval() << endl;

    exp2.print(cout);
    cout << exp2.eval() << endl;
  }
