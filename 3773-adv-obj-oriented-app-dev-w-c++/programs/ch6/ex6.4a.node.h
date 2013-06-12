
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex6.4a.node.h
  // Interface for the class Node
  // Example 6-4, 2nd version    
  #ifndef EX6_4_NODE_H
  #define EX6_4_NODE_H
  class Expression;
  #include <iostream>
  using namespace std;
  class Node {   // abstract
  public:
    friend class Expression;
  protected:  
    Node();
    virtual ~Node();
    virtual void print(ostream&) const = 0;
    virtual double eval() const = 0;
  private:
    int use_; // reference counter
  };
  #endif
