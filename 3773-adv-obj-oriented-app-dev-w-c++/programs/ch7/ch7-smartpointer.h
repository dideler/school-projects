  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch7.smartpointer.h
#ifndef CH7_SMARTPOINTER_H
#define CH7_SMARTPOINTER_H 
  template<typename Body>
  /* Template requirements for Body:
   *   None
   */
  class Handle {
  public:
    explicit Handle(Body* = 0);
    Handle(const Handle&);
    ~Handle();
    Handle& operator=(const Handle&);
    Body* operator->();
    Body& operator*();
  private:
    Body* bridge_;
    int* counter_;
  };
#endif

