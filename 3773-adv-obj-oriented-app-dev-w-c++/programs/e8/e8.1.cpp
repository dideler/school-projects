  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 8.1
  //  the version with dequeus does not compile using gnu c++, it works fine with visual C++
  // Therefore deques are commented here  
  // Notes re design
  // Company2 is the most general class, any number of employees can be hired
  // Company1 is a class derived from Company2, only 10 employees can be hired
  // Constructors for both classes have an integer parameter representing the implementation
  //  0 for lists, 1 for vectors and 2 for deques
  // The following inheritance tree is used for implementation of collections:
  // The base class CollectionIfc is an abstract class, which defines an interface common
  // for all collections
  // There are three derived classes; for lists its is CollectionList
  //    for vectors it is CollectionVector, and for deques it is CollectionDeque
#include <iostream>
using namespace std;
#include "e8.1-company1.h"
#include "e8.1-company2.h"

  int main() {
    // starting with the list representation
    Company1 c1(0);
    try {
      c1.hire("john", 12.99);
      c1.hire("john", 23.22);
      c1.hire("Mary", 100);
      vector<int> i = c1.id("john");
      vector<int> j = c1.id("Mary");
      cout << "There are " << i.size() << " employees John" << endl;
      cout << "There are " << j.size() << " employees Mary" << endl;   
      cout << "first employee: " << i[0] << " " << c1.name(i[0]) << " " << 
        c1.salary(i[0]) << endl;
      cout << "second employee: " << i[1] << " " << c1.name(i[1]) << " " << 
        c1.salary(i[1]) << endl; 
      cout << "third employee: " << j[0] << " " << c1.name(j[0]) << " " << 
        c1.salary(j[0]) << endl; 
      c1.setSalary(i[1], 234.55);
      cout << "second employee with new salary: " << i[1] << " " << c1.name(i[1]) << " " 
         << c1.salary(i[1]) << endl;  
      cout << "firing second john " << i[1] << endl;
      c1.fire(i[1]);
      // reset vectors of ids
      i = c1.id("john");
      j = c1.id("Mary"); 
      cout << "There are " << i.size() << " employees John" << endl;
      cout << "first employee: " << i[0]  << " "<< c1.name(i[0]) << " " << 
        c1.salary(i[0]) << endl;
      cout << "second employee: " << j[0] << " " << c1.name(j[0]) << " " << 
        c1.salary(j[0]) << endl; 
      cout << "firing non-existing employee" << endl;
      c1.fire(i[2]);
    } catch(range_error& e) {
      cout << e.what() << endl;
    }
    // another company
    Company2 c2(1, 0);  // size 1
    try {
      c2.hire("john", 12.99);
      c2.hire("john", 23.22); 
    } catch(range_error& e) {
      cout << e.what() << endl;
    }     

   // other representations
   // vector:

    Company1 c3(1);
    try {
      c3.hire("john", 12.99);
      c3.hire("john", 23.22);
      c3.hire("Mary", 100);
      vector<int> i = c3.id("john");
      vector<int> j = c3.id("Mary");
      cout << "There are " << i.size() << " employees John" << endl;
      cout << "There are " << j.size() << " employees Mary" << endl;   
      cout << "first employee: " << i[0] << " " << c3.name(i[0]) << " " << 
        c3.salary(i[0]) << endl;
      cout << "second employee: " << i[1] << " " << c3.name(i[1]) << " " << 
        c3.salary(i[1]) << endl; 
      cout << "third employee: " << j[0] << " " << c3.name(j[0]) << " " << 
        c3.salary(j[0]) << endl; 
      c3.setSalary(i[1], 234.55);
      cout << "second employee with new salary: " << i[1] << " " << c3.name(i[1]) << " " 
         << c3.salary(i[1]) << endl;  
      cout << "firing second john " << i[1] << endl;
      c3.fire(i[1]);
      // reset vectors of ids
      i = c3.id("john");
      j = c3.id("Mary"); 
      cout << "There are " << i.size() << " employees John" << endl;
      cout << "first employee: " << i[0]  << " "<< c3.name(i[0]) << " " << 
        c3.salary(i[0]) << endl;
      cout << "second employee: " << j[0] << " " << c3.name(j[0]) << " " << 
        c3.salary(j[0]) << endl; 
      cout << "firing non-existing employee" << endl;
      c3.fire(i[2]);
    } catch(range_error& e) {
      cout << e.what() << endl;
    }
    // another company
    Company2 c4(1, 1);  // size 1
    try {
      c4.hire("john", 12.99);
      c4.hire("john", 23.22); 
    } catch(range_error& e) {
      cout << e.what() << endl;
    }     

/*
   // deque

    Company1 c5(2);
    try {
      c5.hire("john", 12.99);
      c5.hire("john", 25.22);
      c5.hire("Mary", 100);
      vector<int> i = c5.id("john");
      vector<int> j = c5.id("Mary");
      cout << "There are " << i.size() << " employees John" << endl;
      cout << "There are " << j.size() << " employees Mary" << endl;   
      cout << "first employee: " << i[0] << " " << c5.name(i[0]) << " " << 
        c5.salary(i[0]) << endl;
      cout << "second employee: " << i[1] << " " << c5.name(i[1]) << " " << 
        c5.salary(i[1]) << endl; 
      cout << "third employee: " << j[0] << " " << c5.name(j[0]) << " " << 
        c5.salary(j[0]) << endl; 
      c5.setSalary(i[1], 254.55);
      cout << "second employee with new salary: " << i[1] << " " << c5.name(i[1]) << " " 
         << c5.salary(i[1]) << endl;  
      cout << "firing second john " << i[1] << endl;
      c5.fire(i[1]);
      // reset vectors of ids
      i = c5.id("john");
      j = c5.id("Mary"); 
      cout << "There are " << i.size() << " employees John" << endl;
      cout << "first employee: " << i[0]  << " "<< c5.name(i[0]) << " " << 
        c5.salary(i[0]) << endl;
      cout << "second employee: " << j[0] << " " << c5.name(j[0]) << " " << 
        c5.salary(j[0]) << endl; 
      cout << "firing non-existing employee" << endl;
      c5.fire(i[2]);
    } catch(range_error& e) {
      cout << e.what() << endl;
    }
    // another company
    Company2 c6(1, 2);  // size 1
    try {
      c6.hire("john", 12.99);
      c6.hire("john", 25.22); 
    } catch(range_error& e) {
      cout << e.what() << endl;
    }     
*/
}

