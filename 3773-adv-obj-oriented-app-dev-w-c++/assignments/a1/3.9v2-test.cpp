/**
 * Exercise 3.9
 * From the book "C++ Programming with Design Patterns Revealed"
 *  
 * @author Dennis Ideler <ideler.dennis@gmail.com>
 */

#include <iostream>
#include "3.9v2-gift.h"
using std::cout;
using std::endl;

int main()
{
  //Item item("Pen", 2023.5032); // Abstract class, cannot instantiate.
  //cout << item << endl;
  Book book("LOTR", 19.95);
  cout << book << endl;
  
  Flower flower("Lilly", 2.30, Flower::Colour::RED);
  cout << flower << endl;
  
  Gift gift1(flower);
  cout << gift1 << endl;

  Gift gift2(book);
  cout << gift2 << endl;
  
  Gift gift(Flower("Tulip", 4.00, Flower::Colour::WHITE));
  
  Flower f;
  cout << f << endl;
  cout << f.name() <<  " " << f.price() << " " << f.colour() << endl;
}
