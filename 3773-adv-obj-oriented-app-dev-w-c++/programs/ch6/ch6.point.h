
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch6.point.h
  #ifndef CH6_POINT_H
  #define CH6_POINT_H
  class Point { 
  public:
    Point(double = 0, double = 0);
    virtual ~Point();  
    double getX() const;
    double getY() const;
  private:
    double x_;
    double y_;
  };
  #endif 

