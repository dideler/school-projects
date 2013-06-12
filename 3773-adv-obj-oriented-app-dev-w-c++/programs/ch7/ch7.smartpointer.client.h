  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch7.smartpointer.client.h
  // Sample main program.
  // Note: this header file includes the implementation!
#include "ch7.smartpointer.cpp"
#include "ch7.point.h"
#include <iostream>
using namespace std;
#include <vector>
#include <list>
typedef Handle<Point> Hpoint;

void show(const Hpoint& h) {
  cout << h->getX() << " " << h->getY() << endl;
}

int main() {

  vector<Hpoint> v;
  list<Hpoint> h;
  // insert two points
  Hpoint p(new Point(1, 2));
  v.push_back(p);
  h.push_front(p);
  Hpoint q(new Point(1, 3));
  v.push_back(q);
  h.push_front(q);
  // print
  show(v[0]); show(v[1]);
  show(h.front()); show(h.back());

  // modify
  v[0]->setX(3);
  h.back()->setY(5);
  // print
  show(v[0]); show(v[1]);
  show(h.front()); show(h.back());

}

