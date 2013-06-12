
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.3.registarwithattributes.h
  #ifndef EX6_3_REGISTARTWITHATTRIBUTES_H
  #define EX6_3_REGISTARTWITHATTRIBUTES_H
  class Attr;
  #include "ex6.3.registrar.h"
  class RegistrarWithAttributes : public Registrar {
  public:
    RegistrarWithAttributes();
    virtual ~RegistrarWithAttributes();

    virtual void add(const Attr&);
    virtual bool find(const string&, Attr&) const;
    virtual bool remove(const string&, Attr&);
  private:
    AttributedIfc* attrImpl_;
  };
  #endif 

