
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File ex6.1.abstractfile.h

  #ifndef EX6_1_ABSTRACTFILEOPS_H
  #define EX6_1_ABSTRACTFILEOPS_H
  // #include <string>
  class AbstractFileOps {  //abstract
  public:
    virtual long lines() const = 0;  
  //  virtual void clearCache() = 0;
  protected:
 // AbstractFileOps(const string&);
    virtual ~AbstractFileOps();
  };
  #endif

