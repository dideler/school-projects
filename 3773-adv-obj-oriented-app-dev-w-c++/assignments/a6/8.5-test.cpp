/**
 * COMP 3773 - Assignment 6 - Exercise 8.5
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Simple tests for the SafeList class.
 *
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date August 2013
 * @version 1.0
 */

#include <iostream>
#include <list> // TODO
#include <vector>
using namespace std;

#include "8.5-safelist.h"

template <typename Container>
void print(const Container &c)
{
  for (const auto &e : c)
    cout << e << ' ';
  cout << endl;
}

int main()
{
  try
  {
    SafeList<int> sl;

    // First, let's throw a bunch of exceptions to show that they work.
    cout << "### Operations that should fail" << endl;

    // Pop front when empty should throw.
    try { sl.pop_front(); }
    catch (const domain_error& e) { cout << e.what() << endl; }

    // Pop back when empty should throw.
    try { sl.pop_back(); }
    catch (const domain_error& e) { cout << e.what() << endl; }
    
    // Access front when empty should throw.
    try { sl.front(); }
    catch (const domain_error& e) { cout << e.what() << endl; }

    // Access back when empty should throw.
    try { sl.back(); }
    catch (const domain_error& e) { cout << e.what() << endl; }

    // Pushing an unrelated type (in front) should throw.
    try { sl.push_front("foo"); }
    catch (const domain_error& e) { cout << e.what() << endl; }
    
    // Pushing an unrelated type (in back) should throw.
    try { sl.push_back("bar"); }
    catch (const domain_error& e) { cout << e.what() << endl; }
 
    // Assigning with a negative size should throw.
    try { sl.assign(-1, 10); }
    catch (const domain_error& e) { cout << e.what() << endl; }

    // Create a vector to use in testing operations with ranges.
    vector<int> v(5, 10); // 5 elements of value 10.
    auto iter = v.begin();
    ++iter;

    // Assigning with an invalid range should throw.
    try { sl.assign(iter, v.begin(), v.end()); } // Notice the 3rd iterator arg.
    catch (const domain_error& e) { cout << e.what() << endl; }

    // Inserting an unrelated type should throw.
    try { sl.insert(sl.begin(), "foo"); }
    catch (const domain_error& e) { cout << e.what() << endl; }
    
    // Inserting many elements of unrelated type should throw.
    try { sl.insert(sl.begin(), 5, "bar"); }
    catch (const domain_error& e) { cout << e.what() << endl; }
    
    // Inserting a negative amount of elements should throw.
    try { sl.insert(sl.begin(), -1, 10); }
    catch (const domain_error& e) { cout << e.what() << endl; }
   
    // Resizing with a negative size should throw.
    try { sl.resize(-1); }
    catch (const domain_error& e) { cout << e.what() << endl; }

    // Now let's perform some operations that shouldn't fail.
    cout << "\n### Operations that should pass" << endl;

    sl.push_back(1);
    sl.push_back(2);
    sl.push_back(3);
    print(sl);

    cout << "size = " << sl.size() << endl;
    cout << "front = " << sl.front() << endl;
    cout << "back = " << sl.back() << endl;

    cout << "overwriting by assigning two elements" << endl;
    sl.assign(2, 100); print(sl);
    
    cout << "overwriting by assigning vector" << endl;
    sl.assign(v.begin(), v.end()); print(sl);

    auto it = sl.begin(); ++it;
    cout << "inserting " << *sl.insert(it, 123) << endl;
    print(sl);

    cout << "inserting first two elements at front" << endl;
    sl.insert(sl.begin(), sl.begin(), it);
    print(sl);


    cout << "erasing element at iterator it: " << *--it << endl;
    sl.erase(it);
    print(sl);

    cout << "distance front to end = " << distance(sl.begin(), sl.end())
         << endl;
    cout << "erasing elements from front to end" << endl;
    sl.erase(sl.begin(), sl.end());
    cout << "new distance front to end = " << distance(sl.begin(), sl.end())
         << endl;
    
    cout << "resizing with 5 elements of value 9" << endl;
    sl.resize(5, 9);
    print(sl);

    cout << "resizing to 10 elements (new elements have default value)" << endl;
    sl.resize(10); // Default int value is 0.
    print(sl);
  }
  catch (const domain_error &e)
  {
    cout << e.what() << endl;
  }
  catch (const bad_alloc &e)
  {
    cout << e.what() << endl;
  }
  catch (const exception &e)
  {
    cout << e.what() << endl;
  }
  catch (...)
  {
    cout << "Unknown exception" << endl;
  }
}
