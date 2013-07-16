/**
 * COMP 3773 - Assignment 4 - Exercise 6.3
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Sample main program.
 * Based on example 6.1.
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "6.3-encryption1_product.h"
#include "6.3-encryption2_product.h"
#include <iostream>
#include <string>
using namespace std;

const string ANSI_BOLD = "\033[1m";
const string ANSI_RESET = "\033[0m";

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    cerr << "usage: " << argv[0] << " file1 file2" << endl;
    return 1;
  }

  AbstractProduct* e1 = new Encryption1Product();
  e1->encrypt(argv[1]);
  cout << ANSI_BOLD;
  cout << "Encrypted " << argv[1] << " using algorithm 1" << endl;
  cout << ANSI_RESET << endl;
  e1->decrypt(argv[1]);
  cout << ANSI_BOLD;
  cout << "Decrypted " << argv[1] << " using algorithm 1\n" << endl;
  cout << ANSI_RESET;
  delete e1;

  AbstractProduct* e2 = new Encryption2Product();
  e2->encrypt(argv[2]);
  cout << ANSI_BOLD;
  cout << "Encrypted " << argv[2] << " using algorithm 2" << endl;
  cout << ANSI_RESET << endl;
  e2->decrypt(argv[2]);
  cout << ANSI_BOLD;
  cout << "Decrypted " << argv[2] << " using algorithm 2" << endl;
  cout << ANSI_RESET;
  delete e2;

  return 0;
}
