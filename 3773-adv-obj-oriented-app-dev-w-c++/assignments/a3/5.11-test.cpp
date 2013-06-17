/**
 * COMP 3773 - Assignment 3 - Exercise 5.11
 * From the book "C++ Programming with Design Patterns Revealed"
 *
 * Simple tests for my basic queue class.
 * For simplicity, the empty queue consists of 0s.
 * 
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 * @student# 100122809
 * @date June 2013
 * @version 1.0
 */

#include "5.11-queue.h"
using namespace queue;

#include <iostream>
using namespace std;

int main()
{
  try
  {
    cout << "creating queue of size 3..." << endl;
    Queue q1(3);
    cout << "front = " << q1.front() << ", back = " << q1.back()
         << ", size = " << q1.size() << "\n" << endl;
    cout << "inserting 10..." << endl;
    q1.push(10);
    cout << "front = " << q1.front() << ", back = " << q1.back()
         << ", size = " << q1.size() << "\n" << endl;
    cout << "inserting 20..." << endl;
    q1.push(20);
    cout << "front = " << q1.front() << ", back = " << q1.back()
         << ", size = " << q1.size() << "\n" << endl;
    cout << "inserting 30..." << endl;
    q1.push(30);
    cout << "front = " << q1.front() << ", back = " << q1.back()
         << ", size = " << q1.size() << "\n" << endl;
    cout << "inserting 40... ";
    // Note: We could also call full() before a push instead of blindly pushing.
    try { q1.push(40); } // Queue is full.
    catch(const logic_error& e) { cout << "Exception: " << e.what() << endl; }
    cout << "front = " << q1.front() << ", back = " << q1.back()
         << ", size = " << q1.size() << "\n" << endl;
    cout << "copying queue..." << endl;
    Queue q2 = q1;
    cout << "front = " << q2.front() << ", back = " << q2.back()
         << ", size = " << q2.size() << "\n" << endl;
    cout << "popping element..." << endl;
    q2.pop();
    cout << "front = " << q2.front() << ", back = " << q2.back()
         << ", size = " << q2.size() << "\n" << endl;
    cout << "inserting 40... " << endl;
    q2.push(40);
    cout << "front = " << q2.front() << ", back = " << q2.back()
         << ", size = " << q2.size() << "\n" << endl;
    cout << "popping element..." << endl;
    q2.pop();
    cout << "front = " << q2.front() << ", back = " << q2.back()
         << ", size = " << q2.size() << "\n" << endl;
    cout << "popping element..." << endl;
    q2.pop();
    cout << "front = " << q2.front() << ", back = " << q2.back()
         << ", size = " << q2.size() << "\n" << endl;
    cout << "popping element..." << endl;
    q2.pop();
    cout << "front = " << q2.front() << ", back = " << q2.back()
         << ", size = " << q2.size() << "\n" << endl;
    cout << "popping element... "; // Queue is empty.
    try { q2.pop(); } 
    catch(const logic_error& e) { cout << "Exception: " << e.what() << endl; }
  }
  catch(const bad_alloc&)
  {
    cout << "Failure allocating memory" << endl;
  }
}
