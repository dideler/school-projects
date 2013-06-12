// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// 
// Modified and fixed by Dennis Ideler, March 2013
//
// File: ex2.5.cpp
//
// Copy words from the input file to the output file.
// Pass filenames on the command line as arguments.
//
// Output the total number of words to the standard output
// Return 1 if can't open input file; 2 if can't open output file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    cerr << "Usage: " << argv[0] << " file1 file2" << endl;
    return 1;
  }

  ifstream inFile(argv[1]);
  if (!inFile)
  {
    cerr << "can't open " << argv[1] << endl;
    return 1;
  }

  ofstream outFile(argv[2]);
  if (!outFile)
  {
    cerr << "can't open " << argv[2] << endl;
    return 2;
  }

  string word;
  long wordCounter = 0;
  while (inFile >> word)
  {
    outFile << word << endl;
    wordCounter++;
  }

  cout << "Read " << wordCounter << " words" << endl;
  return 0;
}
