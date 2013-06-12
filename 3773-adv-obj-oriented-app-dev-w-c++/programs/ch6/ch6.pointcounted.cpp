
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch6.pointcounted.cpp
  // Implementation for the class PointCounted

  PointCounted::PointCounted(double x, double y) {
    p_ = new Point(x, y);
    count_ = new int(1);
  }

  PointCounted::PointCounted(const PointCount& pc) {
    count_ = pc.count_;
    p_ = pc.p_;
    ++(*count_);
  }

  PointCounted::PointCounted(const Point& pp) {
    p_ = new Point(pp);
    count_ = new int(1);
  }

  PointCounted::operator=(const PointCount& pc) {
    if(this == &pc)
      return *this;
    ++(*pc.count_);  // RHS has one more reference
    --(*count_);     // LHS has one less reference
    if(*count_ == 0) {  // garbage
      delete p_;
      delete count_;
    }
    count_ = pc.count_;
    p_ = pc.p_;
    return *this;
  }

  PointCounted::~PointCounted() {
    --(*count_);     // one less reference
    if(*count_ == 0) {  // garbage
      delete p_;
      delete count_;
    }
  }

  double PointCounted::getX() const {
    return p_->getX();
  }
