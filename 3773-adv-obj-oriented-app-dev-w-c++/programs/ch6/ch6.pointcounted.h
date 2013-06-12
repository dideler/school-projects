
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // file: ch6.pointcounted.h
  #ifndef CH6_POINTCOUNTED_H
  #define CH6_POINTCOUNTED_H
  class Point;
  class PointCounted {
  public:
    PointCounted(double = 0, double = 0); // creates a point           
    PointCounted(const PointCounted&);
    PointCounted(const Point&);  
    PointCounted& operator=(const PointCounted&);
    ~PointCounted();
    double getX() const;
    double getY() const;
  private:
    Point* p_;
    int* count_;
  };
  #endif 

