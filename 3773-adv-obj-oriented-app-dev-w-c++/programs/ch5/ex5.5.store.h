// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File ex5.5.store.h
//
// Example 5.5
// Interface of class Store

#ifndef STORE_H
#define STORE_H
class Store // abstract base class (due to pure virtual method)
{
 public:
  double getBillableAmount(int) const; // template method
  Store(double pricePerUnit = 1);
  virtual ~Store();
  double getPricePerUnit() const;
  void setPricePerUnit(double);
 protected:
  virtual double getTaxAmount(int) const = 0; // primitive operation
 private:
  double pricePerUnit_;
};
#endif
