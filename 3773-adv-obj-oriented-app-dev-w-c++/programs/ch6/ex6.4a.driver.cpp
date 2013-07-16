// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.4a.driver.cpp
//
// Sample main program for the 2nd version of Example 6-4

#include <iostream>
using namespace std;

#include "ex6.4a.expression.h"
#include "ex6.4a.operatorfactory.h"

int main()
{
  Expression two(2);
  Expression exp1 = Expression(OperatorFactory::makeAddition(), two, 4);
  Expression exp2 = Expression(OperatorFactory::makeTimes(), exp1, exp1);  
  exp1.print(cout);
  cout << endl << exp1.eval() << endl;
  exp2.print(cout);
  cout << endl << exp2.eval()<< endl;
}
