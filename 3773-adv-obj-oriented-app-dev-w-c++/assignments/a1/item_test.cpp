/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#include <iostream>
#include "item.h"
#include "book.h"
using std::cout;
using std::endl;

int main()
{
  //Item item("Pen", 2023.5032);
  //cout << item << endl;
  Book book("LOTR", 19.95);
  cout << book << endl;
}
