
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.2.A.polynomial.h

  #ifndef EX6_2_POLYNOMIALA_H
  #define EX6_2_POLYNOMIALA_H
  class Polynomial : public Function {
  public:
    virtual void display();
  protected:
    Polynomial(string);
  private:
    int* coefficients_;
    int degree_;
  };
  #endif
