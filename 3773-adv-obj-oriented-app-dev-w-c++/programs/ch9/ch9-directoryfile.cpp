  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch9-directoryfile.cpp
  // Example 9.3
#include "ch9-directoryfile.h"
#include <algorithm>

  class Same { // predicate class
  public:
    Same(File* & f) : f_(f) {}
    bool operator()(File*& f) {
       return f->name() == f_->name();
    }
  private:
    File* f_;
  };
  void output(File*& f) { cout << "filename: " << f->name() << endl; }

  void Directory::show() const {
    for_each(children_.begin(), children_.end(),output);
  }

  void Directory::add(File* f) throw(range_error) {
     if(find_if(children_.begin(), children_.end(), Same(f)) != children_.end())
      throw range_error("duplicate name");
    children_.insert(children_.end(), f);
  }

    void Directory::accept(Visitor& v) { 
          // first, visit every child
    for(FileIterator i = children_.begin(); i != children_.end(); ++i) {
      File* f = *i;
      f->accept(v);
    }
    // finally, visit this composite object

       v.visit(this); 
    }
    void Directory::remove(File*) throw(range_error) {}
    Directory::~Directory() {}
    Directory::Directory(const string& s) : File(s) {}

