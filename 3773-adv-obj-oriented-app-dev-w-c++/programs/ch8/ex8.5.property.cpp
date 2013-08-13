// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley

#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <map>
#include <string>
using namespace std;

typedef pair<string, string> STR;

ostream& operator<<(ostream &os, const STR &ip)
{
  os << ip.first << " " << ip.second << endl;
  return os;
}

istream& operator>>(istream &os, STR &ip)
{
  os >> ip.first;
  os >> ip.second;
  return os;
}

class Property
{
 public:
  Property();
  Property(const Property&);
  Property& operator=(const Property&);
  ~Property();
  bool getProperty(const string&, string&) const;
  bool list(const string&) const;  // output
  bool load(const string&);  // input
  void add(const string&, const string&); // add new property
  typedef map<string, string>::const_iterator MI;
 private:
  map<string, string> property_;
};

Property::Property() {}

Property::~Property() {}

void Property::add(const string &s, const string &t) { property_[s] = t; }

bool Property::load(const string &fname)
{
  ifstream ifs(fname.c_str());
  if (!ifs) return false;

  typedef istream_iterator<STR> Input;
  Input eof;
  for (Input i(ifs); i != eof; ++i)
  {
    STR aux = *i;
    property_[aux.first] = aux.second;
  }
  return true;
}

bool Property::list(const string &fname) const
{
  ofstream ofs(fname.c_str());
  if (!ofs) return false;

  typedef ostream_iterator<STR> Output;
  Output o(ofs);
  copy(property_.begin(), property_.end(), o);
  return true;
}

bool Property::getProperty(const string &name, string &value) const
{
  MI i = property_.find(name);
  if (i == property_.end()) return false;
  value = i->second;
  return true;
}
