// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// Implementation of file operations for the class FileOps
// Uses a macro DEB, when defined it shows whether or not cache is used

#include "ex3.3.fileops.h"
//#include <fstream>
//#include <iostream>
//using namespace std;

#define DEB true

long FileOps::lines() const {
#ifdef DEB
  if (linesCached_)
     cout << "returning cached value" << endl;
  else
     cout << "returning non-cached value" << endl;
#endif
  if (linesCached_)
    return lines_;
  lines_ = 0;
  if (!charsCached_)  // cache characters as well
    chars_ = 0;

  char c;
  while (fileVar_.get(c)) {
    if (c == '\n')
      ++lines_;
    if (!charsCached_)
      ++chars_;
  }
  charsCached_ = true;
  linesCached_ = true;
  fileVar_.clear();
  fileVar_.seekg(0);
  return lines_;
}

long FileOps::chars() const {
#ifdef DEB
  if (charsCached_)
     cout << "returning cached value" << endl;
  else
     cout << "returning non-cached value" << endl;
#endif
  if (charsCached_)
    return chars_;
  chars_ = 0;
  if (!linesCached_)
     lines_ = 0;

  char c;
  while (fileVar_.get(c)) {
    chars_++;
    if (!linesCached_ && c == '\n')
      lines_++; 
  }
  linesCached_ = true; 
  charsCached_ = true;
  fileVar_.clear();
  fileVar_.seekg(0);
  return chars_;
}

long FileOps::words() const {
#ifdef DEB
  if (wordsCached_)
     cout << "returning cached value" << endl;
  else
     cout << "returning non-cached value" << endl;
#endif
  if (wordsCached_)
     return words_;
  words_ = 0;
   if (!charsCached_)  // cache characters as well
    chars_ = 0;
  if (!linesCached_) 
     lines_ = 0;

  char c;
  int flag = 1;
  while (fileVar_.get(c)) {
    if (!linesCached_ && c == '\n') 
      lines_++;
    if (!charsCached_)
      chars_++;
    if (c == ' ' || c == '\n' || c == EOF)  // take care of words 
      flag = 1;
    else if (flag) {
      flag = 0;
      words_++;
    }
  }
  charsCached_ = linesCached_ = wordsCached_ = true;
  fileVar_.clear();
  fileVar_.seekg(0);
  return words_;
}

FileOps::FileOps(const string& filename) : fileVar_(filename.c_str()) {
  lines_ = chars_ = words_ = 0;
  linesCached_ = charsCached_ = wordsCached_ = false;
}

FileOps::~FileOps() {
   fileVar_.close();
}

// NOTE: Copy constructor is not implemented.
