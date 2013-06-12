
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.2.A.rational.h
  #ifndef EX6_2_RATIONALA_H
  #define EX6_2_RATIONALA_H
  class Rational : public Function {
  public:
    virtual void display();
  protected:
    Rational(string);
  private:
    int* nomCoefficients_;
    int nomDegree_;
    int* denCoefficients_;
    int denDegree;
  };
  #endif

