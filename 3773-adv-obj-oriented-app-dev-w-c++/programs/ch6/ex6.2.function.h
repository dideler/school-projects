
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.2.function.h

  #ifndef EX6_2_FUNCTION_H
  #define EX6_2_FUNCTION_H
  #include <string>
  class Function {  
  public:
    virtual void display() const = 0;
    Function(const string&);
    virtual ~Function();
  protected:
    string pol_;
  };
  #endif

