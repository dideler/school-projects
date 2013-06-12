
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.2.polynomial.cpp
  // Implementation for the class Polynomial

  #include "ex6.2.polynomial.h"
 // #include <sstream>
  void Polynomial::display() const {

	  cout << "Polynomial" << pol_ << endl;
/*
	  for(int i = 0; i < degree-1_; ++i) 
		  cout << coefficients_[i] << "*x^" << i << " + ";
	  cout << coefficients_[degree_] << "*x^" << degree_ << endl;
 */
  }
  Polynomial::Polynomial(const string& pol) : Function(pol) {
    coefficients_ = 0;
/*
	  degree_ = 0;
      // retrieve degree
	  istringstream is(pol_);
      while(is >> double d) 
		  ++degree_;
      coefficients_ = new int[degree_];
	  // fill in
      istringstream is1(pol_);
      for(int i = 0; i < degree_; ++i) {
          is1 >> coefficients_[i];
*/
  }
  Polynomial::~Polynomial() {
	  delete [] coefficients_;
  }

