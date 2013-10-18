/** Question 1:
  * given n > 0
  * if n is even, divide it by 2
  * else, n is odd and multiply it by 3 and add 1
  ***************************
  * Author:		Dennis Ideler
  * Student#:	4134466
  * Date:		Oct. 20, 2008
  * Course:		COSC 2P03
  * Assignment:	1									*/
  
  import java.util.*;
  import java.io.*;
  
public class Q1 
{
	LinkedList	list;							// holds the sequence lists
	LinkedList	masterList = new LinkedList();	// the master list
	LinkedList	tempList = new LinkedList();	// temp list to help sort
	LinkedList	sortList = new LinkedList();	// the master list but sorted
	
	public Q1()
	{	
		// makes sequenced linked lists for n = 10,11,...,20
		for(int n = 10; n<21; n++)
		{
			sequenceList(n);
		}
		
		System.out.println("Unsorted:");
		// prints out the nodes of the unsorted list
		for(Iterator i = masterList.iterator(); i.hasNext();)
		{
			System.out.println(i.next());
		} System.out.println();
		
		sortList = (LinkedList) gnomeSort(masterList);
		
		System.out.println("Sorted:");
		// prints out the nodes of the sorted list
		for(Iterator i = sortList.iterator(); i.hasNext();)
		{
			System.out.println(i.next());
		} System.out.println();
	}
	
	//creates the sequence and inserts into master list
	public void sequenceList(int n)
	{
		int m;						// holds the value for n mod 2
		list = new LinkedList();	// will hold the sequence of n
		
		//adds the integers of the sequence to the list until sequence reaches 1
		while(true)
		{
			list.addLast(n);
			if(n==1)break;
			m = n%2;
			if(m == 0){ n/=2;}
			else {n = (n*3)+1;}
		}
		masterList.addLast(list);
	}
	
	// this method takes in the list and returns a sorted list using gnome sort
	public LinkedList gnomeSort(LinkedList aList)
	{
	  int i = 1;	// indexer used to iterate through list
	  int j = 2;
	  
	  while(i < aList.size())
	  // when i > list size, the whole list has been passed through
	  {
	  	
	  	if(aList.get(i-1).toString().length() <= aList.get(i).toString().length())
	  	// do not swap, but increment index to iterate through list
	  	{
	  		i = j;
	        j++;
	  	}
	    else  // swap, and step back 1 
	    {	
	    	tempList = (LinkedList) aList.get(i-1);
	   		aList.set(i-1,aList.get(i)); 
	    	aList.set(i,tempList); 
	    	
	        i--;
	        if(i == 0) i = 1;
	        
			/* How to swap two elements (using a temporary variable):
			 *
			 *  List a
			 *  List b
			 *  tempList = a
			 *  a = b
			 *  b = tempList		*/
	    }
	  }
	  return aList;
	}
	
	public static void main(String[]args){new Q1();}
}