
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  //File: ex6.3.attributedifc.h

  #ifndef EX6_3_ATTRIBUTEDIFC_H
  #define EX6_3_ATTRIBUTEDIFC_H
  class Attr;
  class AttributedIfc { // abstract
  public:
    virtual void add(const Attr&) = 0;
    virtual bool find(const string& name, Attr&) const = 0;
    virtual bool remove(const string& name, Attr&) = 0;
  };

