// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.6

#include <string>
#include <map>

#include "ex6.3.attr.h"

class AttributedIfc // abstract
{
 public:
  virtual void add(const Attr&) = 0;
  virtual bool find(const string& name, Attr&) const = 0;
  virtual bool remove(const string& name, Attr&) = 0;
};

class AttributedImp : public AttributedIfc
{
 public:
  virtual void add(const Attr&);
  virtual bool find(const string& name, Attr&) const;
  virtual bool remove(const string& name, Attr&);
  typedef pair<string, Attr> PAIR;
  typedef map<string, Attr>::iterator ITER; // bidirectional
  typedef map<string, Attr>::const_iterator C_ITER; // bidirectional
  ITER begin();
  ITER end();
 private:
  map<string, Attr> impl_;
};

void AttributedImp::add(const Attr &a) { impl_[a.getName()] = a; }

bool AttributedImp::find(const string &name, Attr &a) const
{
  C_ITER i = impl_.find(name);
  if (i == impl_.end()) return false;
  a = i->second; 
  return true;
}

bool AttributedImp::remove(const string &name, Attr &a)
{
// map<string, Attr>::iterator i = impl_.find(name);
  ITER i = impl_.find(name);
  if (i == impl_.end()) return false;
  a = i->second;
  impl_.erase(i);
  return true;
}

AttributedImp::ITER AttributedImp::begin() { return impl_.begin(); }

AttributedImp::ITER AttributedImp::end() { return impl_.end(); }

int main()
{
  AttributedImp* at = new AttributedImp;
  for (AttributedImp::ITER i = at->begin(); i != at->end(); ++i) 
    cout << "attribute name " << i->first << endl;
}
