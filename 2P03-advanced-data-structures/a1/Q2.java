/** Question 2:
  * given a list of integers, print out the elements that occur in positions 
  * of prime numbers, in the SAME ORDER as they occur in the list, 
  * followed by all other elements in the REVERSE ORDER as they occured in the 
  * list.
  *
  * A positive integer p is a prime number if p is not 0 or 1 (base cases)
  * and if p has no factor except itself and 1.
  *
  * List of primes: 2,3,5,7,11,13,17,19,23,29,31,37,41,.......(inf. many primes)
  *
  * Prime number formula: m = p1 × p2 × p3 × ... × pK + 1,
  *						  where p1, p2, p3, ..., pK are prime numbers
  ***************************
  * Author:		Dennis Ideler
  * Student#:	4134466
  * Date:		Oct. 20, 2008
  * Course:		2P03
  * Assignment: 1														*/
  
  import java.io.*;
  import java.util.*;
  
public class Q2
{
	LinkedList aList = new LinkedList();
	LinkedList sortList = new LinkedList();
		
	public Q2()throws IOException
	{
		//datafile.txt must be in same folder as project to locate it
		BufferedReader br = new BufferedReader(new FileReader("datafile.txt"));		
		
		int unicode;
		String temp = "";
		
		while(br.ready()) // false when all is read
		{	
			unicode = br.read();
			
			//if it's a #, temporarily store it
			if(unicode>=48 && unicode<=57) temp += (char)unicode;
			
			// if it's not a #, add temp to list and clear temp
			else if(unicode < 48 || unicode > 57)
			{
				aList.addLast(temp);
				temp = "";
			}
		}
		aList.addLast(temp); // add the last digit in the sequence, to the LL
		
		System.out.println("input:\n"+aList+"\n");
		
		for(int i = aList.size()-1; i!=-1; i--)
		{
			// if digit is not in a prime position, add to end of list
			if(!isPrime(i+1)) sortList.addLast(aList.get(i));
			
			// else digit is in a prime position, add to front of list
			else sortList.addFirst(aList.get(i));
		} 
		System.out.println("output:\n"+sortList+"\n");
		br.close();
	}
    
    public boolean isPrime(long p)
    {
    	long test = 2;
    	
    	if(p <= 1) return false;		// if 1,0 or smaller, then not prime
    	if(p == 2) return true;
    	
    	while(test < p)
    	{
    		if(p % test == 0) return false;
    		else if(test == 2) test++;
    		else test += 2;
    	}
    	return true;
    }

public static void main(String[]args)throws IOException{new Q2();}
	
}