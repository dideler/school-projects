  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ex3.1.student.h
  // Header file with the class definition

  #ifndef STUDENT_H
  #define STUDENT_H

  class Student { 
  public:
    Student(long);     // declaration of a constructor operation
    void modify(long); // declaration of an operation 
    long get() const;  // added to be able to show something
  private:
    long number_;      // attribute
  };  // note the semicolon

  #endif

