// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ex3.3.fileops.h
// This class provides three simple file operations
//   to compute the number of characters, words and lines, respectively
// Data are cached

#ifndef FILEOPS_H
#define FILEOPS_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FileOps {
 public:
  explicit FileOps(const string&);
  FileOps(const FileOps&);
  ~FileOps();
  long lines() const;
  long words() const;
  long chars() const;
 private:
  mutable ifstream fileVar_;
  // cache for internal resul
  // mutable means you can modify it in const functions
  // see this rant: http://www.highprogrammer.com/alan/rants/mutable.html
  mutable bool linesCached_; 
  mutable long lines_;
  mutable bool wordsCached_;
  mutable long words_;
  mutable bool charsCached_;
  mutable long chars_;
};

#endif
