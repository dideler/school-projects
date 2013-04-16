/**
 * A program that prints which lines differ between two text files.
 * If files are identical, nothing is printed.
 * Comparison stops as soon as one of the files runs out of contents.
 * Usage: progname file1 file2
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
  if (argc != 3)
  {
    cerr << "Usage: " << argv[0] << " file1 file2" << endl;
    return 1;
  }
  
  ifstream file1(argv[1]);
  if (!file1)
  {
    cerr << "Can't open " << argv[1] << endl;
    return 1;
  }
  ifstream file2(argv[2]);
  if (!file2)
  {
    cerr << "Can't open " << argv[2] << endl;
    return 1;
  }

  string linef1, linef2;
  for (long line_num = 1; getline(file1, linef1) && getline(file2, linef2); ++line_num)
  {
    if (linef1.compare(linef2) != 0)
      cout << "Line " << line_num << " differs" << endl;
  }

  file1.close();
  file2.close();

  return 0;
} 
