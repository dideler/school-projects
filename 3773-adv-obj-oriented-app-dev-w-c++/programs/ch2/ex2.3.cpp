/**  
* Tomasz Muldner, September 2001
* A program for the book:
*  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
*
* Modified by Dennis Ideler, March 2013
* 
* File: ex2.3.cpp
* The program displays all command line arguments, each on a separate line.
*/
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  for (int i = 0; i < argc; i++)
    cout << argv[i] << endl;
}

