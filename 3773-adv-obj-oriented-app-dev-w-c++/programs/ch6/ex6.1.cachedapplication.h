
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.1.cachedapplication.h

  #ifndef EX6_1_CACHEDAPPLICATION_H
  #define EX6_1_CACHEDAPPLICATION_H
  #include <string>
  #include "ex6.1.abstractapplication.h"
  #include "ex6.1.cachedfileops.h"
  class CachedApplication : public AbstractApplication { // implements
  public:
    CachedApplication(const string&);
    ~CachedApplication();
    virtual CachedFileOps* factoryMethod() const;
    void clearCache();
  private:
    string filename_;
  };
  #endif

