// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
// File: ch3-account.h
// Acount for Student with a single student represented by a pointer
// Two accessors available: balance() and number()

#ifndef ACCOUNTFORSTUDENT_H
#define ACCOUNTFORSTUDENT_H
class Student; // forward declaration?
class AccountForStudent {
 public:
  AccountForStudent(long number, double balance);
  AccountForStudent(const AccountForStudent &from);
  ~AccountForStudent();
  double balance() const;
  long number() const; 
 private:
  Student* stud_; // pointer
  double balance_;
};
#endif
