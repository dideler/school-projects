// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley

#include <iostream>
using namespace std;
#include "ch5.student.h"
#include "ch5.studentwithaccount.h"

int main()
{
  StudentWithAccount s(100, "John", 12); // id, name, balance
  cout << s.getNumber() << endl;
  cout << s.getName() << endl;
  cout << s.getBalance() << endl;
  s.setBalance(200);
  s.printInfo();
  Student t(100, "mary");
  s.info(t, s);
}
