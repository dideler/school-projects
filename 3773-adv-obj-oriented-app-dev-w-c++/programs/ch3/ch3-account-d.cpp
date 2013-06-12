// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ch3-account-d.cpp
// Simple tester for the account for student
#include "ch3-account.h" 
#include <iostream>
using namespace std;

int main() {
  AccountForStudent afs(123, 10.2);
  cout << "balance = " << afs.balance() << "; number = " << afs.number() << endl;
  AccountForStudent afs2(afs);
  cout << "balance = " << afs2.balance() << "; number = " << afs2.number() << endl;
  AccountForStudent afs3 = afs2;
  cout << "balance = " << afs3.balance() << "; number = " << afs3.number() << endl;
}
