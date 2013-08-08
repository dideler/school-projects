// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// Exercise 8.1
//
// - Company2 is the most general class, any number of employees can be hired.
// - Company1 is a class derived from Company2, only 10 employees can be hired.
// - Constructors for both classes have an integer parameter representing the
//   implementation: 0 = lists, 1 = vectors, 2 = deques. FIXME use enums
// - The following inheritance tree is used for implementation of collections:
//   - Base class CollectionIfc is an abstract class used as a pure interface.
//     It defines a common interface for all collections derived from it.
//   - Three derived classes:
//     1. lists -> CollectionList
//     2. vectors -> CollectionVector
//     3. deques -> CollectionDeque

#include <iostream>
using namespace std;

#include "e8.1-company1.h"
#include "e8.1-company2.h"

int main()
{
  try // Test list representation (CollectionList).
  {
    Company1 c1(0);
    c1.hire("John", 12.99);
    c1.hire("John", 23.22);
    c1.hire("Mary", 100);
    vector<int> i = c1.id("John");
    vector<int> j = c1.id("Mary");
    cout << "There are " << i.size() << " employees named John" << endl;
    cout << "There are " << j.size() << " employees named Mary" << endl;   
    cout << "First employee: " << i[0] << " " << c1.name(i[0]) << " "
         << c1.salary(i[0]) << endl;
    cout << "Second employee: " << i[1] << " " << c1.name(i[1]) << " "
         << c1.salary(i[1]) << endl;
    cout << "Third employee: " << j[0] << " " << c1.name(j[0]) << " "
         << c1.salary(j[0]) << endl;
    c1.setSalary(i[1], 234.55);
    cout << "Second employee with new salary: " << i[1] << " " << c1.name(i[1])
         << " " << c1.salary(i[1]) << endl;
    cout << "Firing second John " << i[1] << endl;
    c1.fire(i[1]);

    // Reset vectors of IDs.
    i = c1.id("John");
    j = c1.id("Mary"); 
    cout << "There are " << i.size() << " employees John" << endl;
    cout << "First employee: " << i[0]  << " "<< c1.name(i[0]) << " "
         << c1.salary(i[0]) << endl;
    cout << "Second employee: " << j[0] << " " << c1.name(j[0]) << " "
         << c1.salary(j[0]) << endl; 
    cout << "Firing non-existing employee" << endl;
    c1.fire(i[2]);
  }
  catch(range_error& e) { cout << e.what() << endl; }

  // Another company with no employee limit.
  try
  {
    Company2 c2(1, 0); // Size 1.
    c2.hire("John", 12.99);
    c2.hire("John", 23.22); // Error, list is full.
  }
  catch(range_error& e) { cout << e.what() << endl; }     

  cout << endl;

  try // Test vector representation.
  {
    Company1 c3(1);
    c3.hire("John", 12.99);
    c3.hire("John", 23.22);
    c3.hire("Mary", 100);
    vector<int> i = c3.id("John");
    vector<int> j = c3.id("Mary");
    cout << "There are " << i.size() << " employees named John" << endl;
    cout << "There are " << j.size() << " employees named Mary" << endl;   
    cout << "First employee: " << i[0] << " " << c3.name(i[0]) << " "
         << c3.salary(i[0]) << endl;
    cout << "Second employee: " << i[1] << " " << c3.name(i[1]) << " "
         << c3.salary(i[1]) << endl;
    cout << "Third employee: " << j[0] << " " << c3.name(j[0]) << " "
         << c3.salary(j[0]) << endl;
    c3.setSalary(i[1], 234.55);
    cout << "Second employee with new salary: " << i[1] << " " << c3.name(i[1])
         << " " << c3.salary(i[1]) << endl;
    cout << "Firing second John " << i[1] << endl;
    c3.fire(i[1]);

    // Reset vectors of IDs.
    i = c3.id("John");
    j = c3.id("Mary"); 
    cout << "There are " << i.size() << " employees John" << endl;
    cout << "First employee: " << i[0]  << " "<< c3.name(i[0]) << " "
         << c3.salary(i[0]) << endl;
    cout << "Second employee: " << j[0] << " " << c3.name(j[0]) << " "
         << c3.salary(j[0]) << endl;
    cout << "Firing non-existing employee" << endl;
    c3.fire(i[2]);
  }
  catch(range_error& e) { cout << e.what() << endl; }

  try
  {
    Company2 c4(1, 1); // Size 1.
    c4.hire("John", 12.99);
    c4.hire("John", 23.22); 
  }
  catch(range_error& e) { cout << e.what() << endl; }     

  cout << endl;

  try // Test deque representation.
  {
    Company1 c5(2);
    c5.hire("John", 12.99);
    c5.hire("John", 25.22);
    c5.hire("Mary", 100);
    vector<int> i = c5.id("John");
    vector<int> j = c5.id("Mary");
    cout << "There are " << i.size() << " employees John" << endl;
    cout << "There are " << j.size() << " employees Mary" << endl;
    cout << "First employee: " << i[0] << " " << c5.name(i[0]) << " "
         << c5.salary(i[0]) << endl;
    cout << "Second employee: " << i[1] << " " << c5.name(i[1]) << " "
         << c5.salary(i[1]) << endl;
    cout << "Third employee: " << j[0] << " " << c5.name(j[0]) << " "
         << c5.salary(j[0]) << endl;
    c5.setSalary(i[1], 254.55);
    cout << "Second employee with new salary: " << i[1] << " " << c5.name(i[1])
         << " " << c5.salary(i[1]) << endl;
    cout << "Firing second John " << i[1] << endl;
    c5.fire(i[1]);

    // Reset vectors of IDs.
    i = c5.id("John");
    j = c5.id("Mary");
    cout << "There are " << i.size() << " employees John" << endl;
    cout << "First employee: " << i[0]  << " "<< c5.name(i[0]) << " "
         << c5.salary(i[0]) << endl;
    cout << "Second employee: " << j[0] << " " << c5.name(j[0]) << " "
         << c5.salary(j[0]) << endl; 
    cout << "Firing non-existing employee" << endl;
    c5.fire(i[2]);
  }
  catch(range_error& e) { cout << e.what() << endl; }

  // Another company.
  try
  {
    Company2 c6(1, 2); // Size 1.
    c6.hire("John", 12.99);
    c6.hire("John", 25.22); 
  }
  catch(range_error& e) { cout << e.what() << endl; }
}
