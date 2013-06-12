
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  //File: ex6.3.student.h
  #ifndef EX6_3_STUDENT_H
  #define EX6_3_STUDENT_H
  class Student {
  public:
    explicit Student(long);
    long getId() const;
  private:
    long id_;
  };
  #endif 

