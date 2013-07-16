// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ex6.2.rational.cpp
//
// Implementation for the class Rational

#include "ex6.2.rational.h"
// #include <sstream>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

void Rational::display() const
{
  // split a string
  string::size_type pos = pol_.find_first_of('/');
  string nom = pol_.substr(0, pos);
  string den = pol_.substr(pos+1, pol_.length()-pos);
  cout << "Rational" << endl;
  cout << nom << endl;
  cout << "-----------------" << endl;
  cout << den << endl;

  /*
  for(int i = 0; i < nomDegree_-1_; ++i) 
    cout << nomCoefficients_[i] << "*x^" << i << " + ";
  cout << nomCoefficients_[nomDegree__] << "*x^" << nomDegree__ << endl;
  cout << "----------------------------------" << endl;
  for(int i = 0; i < denDegree_-1_; ++i) 
    cout << denCoefficients_[i] << "*x^" << i << " + ";
  cout << denCoefficients_[denDegree__] << "*x^" << denDegree__ << endl;
  */
}

Rational::Rational(const string& pol) : Function(pol)
{
  nomCoefficients_ = denCoefficients_  = 0;

  /*
  nomDegree__ = 0;
    // retrieve nomDegree_
  istringstream is(nom);
    while(is >> double d) 
    ++nomDegree__;
    nomCoefficients_ = new int[nomDegree__];
  // fill in
    istringstream is1(nom);
    for(int i = 0; i < nomDegree__; ++i) {
        is1 >> nomCoefficient_[i];

    denDegree__ = 0;
    // retrieve denDegree_
  istringstream is2(den);
    while(is2 >> double d) 
    ++denDegree__;
    denCoefficients_ = new int[denDegree__];
  // fill in
    istringstream is3(den);
    for(int i = 0; i < denDegree__; ++i) {
        is3 >> denCoefficient_[i];
    */
}

Rational::~Rational()
{
  delete [] nomCoefficients_;
  delete [] denCoefficients_;
}
