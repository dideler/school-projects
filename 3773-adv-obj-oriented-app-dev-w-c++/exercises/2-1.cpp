/**
 * Output the size of all primitive data types.
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  cout << "bool = " << sizeof(bool) << " bytes" << endl;
  cout << "char = " << sizeof(char) << " bytes" << endl;
  cout << "short = " << sizeof(short) << " bytes" << endl;
  cout << "int = " << sizeof(int) << " bytes" << endl;
  cout << "long = " << sizeof(long) << " bytes" << endl;
  cout << "float = " << sizeof(float) << " bytes" << endl;
  cout << "double = " << sizeof(double) << " bytes" << endl;
  return 0;
} 
