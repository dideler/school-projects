#include <iostream>
#include <string>
using namespace std;

class X
{
 public: 
  virtual void show(string s="") const { cout << "X::show(); " << s << " " << i_ << endl; }
  X(int i) : i_(i) { show(); }
  virtual ~X() { cout << "~X" << endl; }
 private:
  int i_;
};

class Y : public X
{
 public: 
  virtual void show(string s="") const { cout << "Y::show(); " << s << " " << d_ << endl; }
  Y(int i, double d) : X(i), d_(d) { show(); }
  ~Y() { cout << "~Y" << endl; }
 private:
  double d_;
};

class Z : public Y
{
 public: 
  virtual void show(string s="") const { cout << "Z::show(); " << s << " " << s_ << endl; }
  Z(string s, int i, double d) : Y(i, d), s_(s) { show(); }
  ~Z() { cout << "~Z" << endl; }
 private:
  string s_;
};

int main()
{
  X* m = new Y(3, 3.5); // downcast
  m->show("2");
  delete m;
  m = new Z("Zs", 4, 4.5);
  m->show("3");
  delete m;
  /* Output
      X::show();  3     - X* m = new Y(3, 3.5); because X() is called in Y()
      Y::show();  3.5   -                       because of Y()
      Y::show(); 2 3.5  - m->show("2");
      ~Y                - delete m; because cleanup starts and derived class...
      ~X                -           and moves up to base class, only because destructor was made virtual!
      X::show();  4     - m = new Z("Zs", 4, 4.5); because Z() -> Y() -> X()
      Y::show();  4.5   - 
      Z::show();  Zs    - 
      Z::show(); 3 Zs   - m->show("3");
      ~Z                - delete m; cleanup starts at derived class and moves up (virtual destructors)
      ~Y
      ~X
  */
}
