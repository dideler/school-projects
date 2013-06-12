
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.Exponent.cpp
  // Implementation for the class Exponent
  // Example 6-4, 2nd version   
  #include "ex6.4a.exponent.h"
  #include "ex6.4a.binarynode.h"
  #include <cmath>
  double Exponent::eval() const {
    BinaryNode* p;
    p = dynamic_cast<BinaryNode*>(owner_);
    if(p == 0) {
      cerr << "this cannot happen" << endl;
      exit(1);
    }
    return pow(p->getLeft(),p->getRight());
  }

  Exponent* Exponent::clone() const {
     return new Exponent(*this);
  }
 
  Exponent::Exponent(const string& n) : AbstractOperator(n) {}
  Exponent::~Exponent() {}

