
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  ////////////////////////
  // File: example.cpp
  // Evaluation of simple arithmetic expressions in postfix notation
  //  with addition, subtraction and multiplication, and integer arguments
  //  using a user-defined stack
  #include <stdexcept>
  #include <iostream>
  #include <cctype>
  using namespace std;
  #include "intstack.h"
  // main program - here is where the execution starts 
  int main() {
    int operand;
    char op;
    const char SENTINEL = '$';
    IntStack s;
    cout << "Enter integer expression in RPN, terminated with "  << SENTINEL
      << endl;
     
    while(1) {
      try { // exceptions
        if(cin >> op) {            // get a single char 
          if(isdigit(op)) {        // check if it's a digit
                cin.putback(op);   // put back on input
                cin >> operand;    // read an entire integer
                s.push(operand);
          } else  
                switch(op) {
                case '+': s.push(s.pop() + s.pop()); 
                          break;
                case '-': operand = s.pop();
                          s.push(s.pop() - operand); 
                          break;
                case '*': s.push(s.pop() * s.pop());
                          break;
                case SENTINEL: // end of input
                          operand = s.pop();
                          if(!s.empty()) {
                            cerr << "incorrect expression" << endl;
                            return 1;
                          } else {
                             cout << "result is " << operand << endl;
                             return 0;
                          }
                default:  cerr << "incorrect op" << endl;
                          return 1;
                }
        }
      } catch(const logic_error& e) {
        cout << e.what() << endl;
        return 1;
      }
    }
  }
  // end of file: example.cpp
  /////////////////////////
