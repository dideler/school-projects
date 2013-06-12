
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  //File: ex6.3.attr.h

  #ifndef EX6_3_ATTR_H
  #define EX6_3_ATTR_H
  #include "ex6.3.attributedobject.h"

  class Attr {  // name-value pairs
  public:
    Attr();
    Attr(string, const AttributedObject*);
    Attr(const Attr&);
    virtual ~Attr();
    Attr& operator=(const Attr&);

    virtual string getName() const;
    virtual AttributedObject& getValue() const;
    virtual AttributedObject* setValue(AttributedObject&); // return old value
  private:
    string name_;
    AttributedObject* value_;
  };
#endif
