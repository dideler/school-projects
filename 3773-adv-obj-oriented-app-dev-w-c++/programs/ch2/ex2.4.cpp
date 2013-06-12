// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// 
// Modified and fixed by Dennis Ideler, March 2013
//
// File: ex2.4.cpp
//
// Copy words from the input file to the output file.
// Prompts the user for filenames.
//
// In the output, each word is on a separate line.
// Output the total number of words to the standard output.
// Return 1 if can't open input file; 2 if can't open output file.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string inFileName, outFileName;

  cout << "Enter input and output file names: ";
  cin >> inFileName >> outFileName;

  ifstream inFile(inFileName.c_str());
  if (!inFile)
  {
    cerr << "can't open " << inFileName << endl;
    return 1;
  }

  ofstream outFile(outFileName.c_str());
  if (!outFile)
  {
    cerr << "can't open " << outFileName << endl;
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

