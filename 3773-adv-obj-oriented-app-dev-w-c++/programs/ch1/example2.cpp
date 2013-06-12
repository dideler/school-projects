
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: example2.cpp
  // Evaluation of simple arithmetic expressions in postfix notation
  //  with addition, subtraction and multiplication, and integer arguments
  //  using a user-defined stack
  #include <stack>            // needed to use standard stacks
  #include <iostream>
  #include <ctype.h>
  using namespace std;
 
  int main() {
    int op1, op2;
    char op;
    const char SENTINEL = '$';
    stack<int> s;
    cout << "Enter integer expression in RPN, terminated with" << SENTINEL
      << endl;
     
    int operand;
    while(1) {
        if(cin >> op) {               // get a single char 
          if(isdigit(op)) {           // check if it's a digit
                cin.putback(op);      // put back on input
                cin >> op1;           // read an entire integer
                s.push(op1);
          } else  
                switch(op) {
                case '+': if(s.size() < 2) { // need 2 els
                            cerr << "empty stack " << endl;
                            return 1;
                          }
                          op1 = s.top();
                          s.pop();
                          op2 = s.top();
                          s.pop();
                          s.push(op1 + op2); 
                          break;
                case '*': if(s.size() < 2)  
                            return 1;
                          op1 = s.top();
                          s.pop();
                          op2 = s.top();
                          s.pop();
                          s.push(op1 * op2); 
                          break;
                case '-': if(s.size() < 2)  
                            return 1;
                          op1 = s.top();
                          s.pop();
                          op2 = s.top();
                          s.pop();
                          s.push(op2 - op1); 
                          break;
                case SENTINEL:                    // end of input
                          operand = s.top();
                          if(s.size() > 1) {
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
    }
  }
