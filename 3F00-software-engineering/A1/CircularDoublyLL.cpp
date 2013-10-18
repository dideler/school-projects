/**
A doubly linked circular linked list is an Abstract Data Type (ADT).
There is no first nor last element in that list (i.e. circular LL); instead, one of the elements is considered current.
The "Current" pointer may rotate clockwise or anti-clockwise (i.e. doubly LL), to  refer to the next or previous element, correspondingly.

The operations defined on this ADT include:
1. the deletion of the current element (which should raise an error if the list is empty); [deleteCurrent]
2. inspection of the contents of the current element (again, an error condition is possible here); [getCurrent]
3. making the next element current; [next]
4. making the previous element current; [prev]
5. insertion of a new element before current; [insert before]
6. insertion of a new element after current; [insert after]
7. test if the list is empty. [isListEmpty]

Design a library unit allowing re-use of your ADT in future projects / programs.
The list of operations mentioned above is left incomplete - on purpose. You are requested to:

1. Produce a one-page design document listing the operations you decided to implement.
   For each operation document its results and error conditions it might raise. Remember that the simpler the design the better.
   Similarly, the more general it is, the greater its chances of re-usability.
   Better designs make implementation simple, therefore design deliberately and meticulously.

2. Implement your ADT as a class (if you decided to use C++) or as a package (if you chose Ada2005).
   You should pay special attention to pointers in order to ensure that the list stays correctly circular at all times.

3. Implement a test harness program, capable of thoroughly testing and demonstrating the functional completeness of your design
   and the correctness of your implementation.

4. Run your test program (possibly several times covering various usage scenarios) and submit the test results it produced.
   The format of the printout should make it easy for the marking TA to evaluate your work.
---------------------------------------------------------------------------------------------

@author Dennis Ideler (4134466)
@date October 2009
@version 0.1
*/

#include <exception>
#include <cstdio>
#include <iostream>
using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "Exception: List Empty";
  }
} err;


template <class T>
class Node
{
  public:				// C++ uses public/private sections, unlike Java where scope needs to be tagged with each item
    
    Node();
    
    Node(T d, Node<T> * p, Node<T> * n)	// custom constructor
    {
      this->data = d;	// (*this).data = d;
      this->prev = p;
      this->next = n;
    }

    ~Node()
    {
      //delete(data);	// only needed when data is a pointer
    }


    T data;
    Node * prev;
    Node * next;

};


template <class T>
class LinkedList
{
  public:

	LinkedList()
	{
		size = 0;
		current = new Node<T>(NULL,NULL,NULL);
		current->next = current;	// list is empty, next links to itself
		current->prev = current;	// list empty, prev links to itself
	}

	~LinkedList()
	{
		// list.makeEmpty	optional, not asked for in assignment
		// delete(current);
		current = NULL;
	}

	T getCurrent()	// get data from current node
	{
		if(size == 0) throw err;
		return current->data;
	}

	void deleteCurrent()	// delete current node -- correct or do i need a tmp?
	{
		if(size == 0) throw err;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		size--;
	}

	void nextNode()		// make the next node the current node
	{
		current = current->next;
	}

	void prevNode()		// make the previous node the current node
	{
		current = current->prev;
	}

	void insertAfter(T x)	// insert after current
	{
		// long version
		Node<T> * tmp = new Node<T>(x, current, current->next);
		current->next->prev = tmp;
		current->next = tmp;
		size++;

		/* short version -- not tested */
		// current->next->prev = current->next = new Node(x, current, current->next);
	}
	
	void insertBefore(T x)	// insert before current
	{
		// long version
		Node<T> * tmp = new Node<T>(x, current->prev, current);
		current->prev->next = tmp;
		current->prev = tmp;
		size++;

		/* short version -- not tested */
		// current->prev->next = current->prev = new Node(x, current->prev, current);
	}

	bool isListEmpty()
	{
		return size == 0;
	}

	int getSize()
	{
		return size;
	}

    	int size;

	Node<T> * current;
};


// Test Harness
int main(void)
{
/** new returns a pointer, thus
    LinkedList<int> * LL = new LinkedList<int>();
    then access functions using LL->, which is (*LL).

    when declaring without new (locally), you can access
    functions like LL.function */

	LinkedList<int> LL;

	if(LL.isListEmpty()) cout << "list is empty" << endl;
	try
	{
		cout << "data at current node = " << LL.getCurrent() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	try
	{
		cout << "deleting node in empty list" << endl;
		LL.deleteCurrent();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << "inserting 4 before" << endl;
	LL.insertBefore(4);
	LL.nextNode();
	cout << "data at current node = " << LL.getCurrent() << endl;
	if(!LL.isListEmpty()) cout << "list is not empty" << endl;
	cout << "size = " << LL.getSize() << endl;
	cout << "inserting 6 after" << endl;
	LL.insertAfter(6);
	cout << "size = " << LL.getSize() << endl;
	
	return 0;
}
