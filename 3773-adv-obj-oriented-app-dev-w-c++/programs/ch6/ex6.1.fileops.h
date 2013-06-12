
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File ex6.1.fileops.h
  #ifndef EX6_1_FILEOPS_H
  #define EX6_1_FILEOPS_H
 #include <string>
 #include <fstream>
 #include "ex6.1.abstractfile.h"
  class FileOps : public AbstractFileOps { // implements
  public:
    virtual long lines() const;
  //  virtual void clearCache();
    FileOps(const string&);
    ~FileOps();
  private:
    mutable ifstream fileVar_;
  };
#endif

