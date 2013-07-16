// Tomasz Muldner, September 2001
// A program for the book:
//  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley
// File: ch6.queue.h

#ifndef CH6_QUEUE_H
#define CH6_QUEUE_H

class Queue : private Dequeue // note: private
{
 public:
  using Dequeue::insertL; // restore insertL();
  using Dequeue::removeR; // restore removeR();
  Queue(int size = 10);
  virtual ~Queue();
};

#endif 
