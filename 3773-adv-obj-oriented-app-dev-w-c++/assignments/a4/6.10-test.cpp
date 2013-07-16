/**
 * COMP 3773 - Assignment 4 - Exercise 6.10 (using modified code from 6.9)
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Simple test program.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date July 2013
 * @version 1.0
 */

#include "6.10-mystring.h"
#include <iostream>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

typedef MyString::string mystring;

// Prints string m, character by character.
void show(const mystring& m)
{
  for (int i = 0; i < m.strlen(); ++i)
  {
    try { cout << m.at(i); }
    catch(domain_error& e) { cout << e.what() << endl; }
  }
}

// Prompts user for a char to locate and prints location if found.
void locateChar(const mystring& m)
{
  char c;
  cout << "testing string: ";
  show(m);
  cout << "\nenter a char: ";
  cin >> c;
  int i = m.strpos(c);
  i == -1 ? cout << "not found" : cout << "found at position " << i;
  cout << endl;
}

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    cerr << "usage: " << argv[0] << " string1 string2 " << endl;
    return 1;
  }

  std::string s(argv[1]);
  mystring m1(argv[2]); // Test constructor using C-style string.
  mystring m2(s); // Test constructor using std::string.
  const mystring m3(m2); // Test constructor using custom string.
  mystring m4 = m1; // Test copy assignment operator using custom string.

  locateChar(m1);

  try // testing insert and remove
  {
    // Test insertion into a constant string (returns a new string).
    cout << "\ninsert \"";
    show(m1);
    cout << "\" into \"";
    show(m3);
    cout << "\" at position: ";
    int p;
    cin >> p;
    mystring tmp = insert(m3, p, m1);
    show(tmp); cout << endl;

    // Test insertion into a modifiable string.
    cout << "\ninsert \"";
    show(m2);
    cout << "\" into \"";
    show(m1);
    cout << "\" at position: ";
    cin >> p;
    insert(m1, p, m2);
    show(m1); cout << endl;
  
    // Test removal of a constant string (returns a new string).
    cout << "\nremove characters from \"";
    show(m3); cout << "\"" << endl;
    cout << "start at position: ";
    cin >> p;
    cout << "number of characters to remove: ";
    int l;
    cin >> l;
    tmp = remove(m3, p, l);
    show(tmp); cout << endl;

    // Test removal of a modifiable string.
    cout << "\nremove characters from \"";
    show(m4); cout << "\"" << endl;
    cout << "start at position: ";
    cin >> p;
    cout << "number of characters to remove: ";
    cin >> l;
    remove(m4, p, l);
    show(m4); cout << endl;
  } catch(std::domain_error& e) { cout << e.what() << endl; }
}
