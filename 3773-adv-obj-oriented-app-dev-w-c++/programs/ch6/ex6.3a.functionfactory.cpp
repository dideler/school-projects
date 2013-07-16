// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
//file: ex4.7a.functionfactory.cpp
//
// Implementation for the class FunctionFactory

Function* FunctionFactory::factoryMethod(string s)
{
  s_ = s;
  if (s represents a polynomial)
    return new Polynomial(s);
  if (s represents a rational function)
    return new Rational(s);
  return 0;  // error
}
