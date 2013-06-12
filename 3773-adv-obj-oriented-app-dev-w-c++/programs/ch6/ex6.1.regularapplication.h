
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.1.regularapplication.h

  #ifndef EX6_1_REGULARAPPLICATION_H
  #define EX6_1_REGULARAPPLICATION_H
  #include "ex6.1.abstractapplication.h"
  #include <string>
  #include "ex6.1.fileops.h"
  class RegularApplication : public AbstractApplication { // implements
  public:
    RegularApplication(const string&);
    ~RegularApplication();
    virtual FileOps* factoryMethod() const;
  private:
    string filename_; 
  };
  #endif
