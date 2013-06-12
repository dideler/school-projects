  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch6.dequeue.h;  circular queue of integers
  #ifndef CH6_DEQUEUE_H
  #define CH6_DEQUEUE_H
  class Dequeue { 
  public:
    Dequeue(int size = 10);
    virtual ~Dequeue();
    void insertL(int);
    void insertR(int);
    int removeL();
    int removeR();
  protected:
    int size_;
    int* elem_;  
    int left_
    int right_;
  };
  #endif 

