/** Hash Table that uses Linear probing
  *
  *@author		Dennis Ideler
  *@student#	4134466
  *@course		2P03
  *@assignment	3
  *@question	2															*/
  
package A3;

public class LinearProbing
{
	private static final int DEFAULT_TABLE_SIZE = 23;	// 23 is prime
	private HashEntry [] hashTable;						// array of entry cells
	private int currentSize;						// number of occupied cells
	private int tableSize;
	private int numCollisions;
	
	/** Constructor for hash table
	 *> passes default size to another constructor		*/
	public LinearProbing()
	{
		this(DEFAULT_TABLE_SIZE);
	}
	
	
	/** Constructor for hash table
	 *> allocate space for the table and set each hashEntry reference to null
	 *
	 *@param size the approximate initial size.		*/
	public LinearProbing(int size)
	{
		allocateArray(size);
		makeEmpty();
		tableSize = size;
	}
	
	
	/** Make the hash table empty.
	 *> sets each entry to null.		*/
	public void makeEmpty()
	{
		currentSize = 0;
		
		for(int i = 0; i < hashTable.length; i++)
			hashTable[i] = null;
	}
	
	
	/** Find an item in the hash table
	 *
	 *@param item the item to search for.
	 *@return the matching item.				*/
	public boolean contains(int item)
	{	
		return isActive(findPos(item));
	}
	
	
	/** Insert into the hash table. If item is already present, do nothing.
	 *
	 *@param x the item to insert.						*/
	public void insert(int x)
	{
		int currentPos = findPos(x);
		
		if(isActive(currentPos)) return;
		
		hashTable[currentPos] = new HashEntry(x,true); // insert x as active
		
		if(++currentSize > hashTable.length / 2) rehash(); // rehash when table is half full
	}
	
	
	/** Remove from the hash table by using lazy deletion.
	 *
	 *@param x the item to remove.					*/
	public void remove(int x)
	{
		int currentPos = findPos(x);
		if(isActive(currentPos)) hashTable[currentPos].isActive = false;
	}
	
	
	/** Get table size.
	 *
	 *@return currentSize the size of the table		*/
	public int getTableSize()
	{	return tableSize;	}
	
	
	/** Get the element at a given position in the hash table.
	 *
	 *@return the element in the hash table.		*/
	public int getElement(int pos)
	{
		int element = 0;
		if(isActive(pos)) element = hashTable[pos].element;
		return element;
	}
	
	/** Get number of collisions that occurred.			*/
	public int getCollisions()
	{	return numCollisions;	}
	
	
	/** Create new hash table array
	 *
	 *@param arraySize the (new) size of the array.			*/
	private void allocateArray(int arraySize)
	{
		hashTable = new HashEntry[arraySize];
		tableSize = arraySize;
	}
	
	
	/** Check if a cell exists and if it's active
	 *
	 *@param currentPos the current position you are checking.
	 *@return true if position is active.							*/
	public boolean isActive(int currentPos)
	{
		return hashTable[currentPos] != null && hashTable[currentPos].isActive;
	}
	
	
	/** Performs the linear probing resolution to collisions.
	 *
	 * Linear probing operates by sequentially searching the hash table 
	 * for a free location.
	 *
	 *@param x the item to search for.
	 *@return the position where the search terminates.			*/
	private int findPos(int x)
	{
		numCollisions = 0;
		int currentPos = hashFunction(x);
		
		// if there is a collision, thus,
		// while cell exists and while element does not already exist
		while(hashTable[currentPos]!=null && (hashTable[currentPos].element!=x))
		{
			numCollisions++;
			currentPos++;	// go to next position
				
			// if new location is outofbounds, put back in range by subtracting TableSize
			if(currentPos >= hashTable.length) currentPos -= hashTable.length;
		}
		return currentPos;
	}
	
	
	/** Build another table that's about twice as big (with a new hash function)
	 * and scan down the entire original hash table, computing the new hash value
	 * for each non-deleted element and inserting it into the new table.		*/
	private void rehash()
	{
		HashEntry [] oldHashTable = hashTable; // copy the array
		
		// create a new double-sized empty table
		allocateArray(nextPrime(2 * oldHashTable.length));
		currentSize = 0;
		
		// copy hash table over into new array
		for(int i = 0; i < oldHashTable.length; i++)
		{
			if(oldHashTable[i] != null && oldHashTable[i].isActive)
				insert(oldHashTable[i].element);
		}
	}
	
	
	/** f(n) = (7n-3) mod tableSize
	 *
	 *@param x the item that's being inserted.			*/
	private int hashFunction(int x)
	{
        return (7 * x - 3) % tableSize;
	}
	
	
	/** Finds the next prime closest to n.
	 *
	 *@param n the number where you have to find the next prime from.
	 *@return n the next prime.						*/
	private static int nextPrime(int n)
	{
		if( n % 2 == 0 )
            n++;
		
		while(!isPrime(n))
			n += 2;

        return n;
	}
	
	
	/** Checks if a number is prime.
	 *
	 *@param n the number to check.
	 *@return true if prime, else false.			*/
	private static boolean isPrime(int n)
	{
		if( n == 2 || n == 3 )
            return true;

        if( n == 1 || n % 2 == 0 )
            return false;

        for( int i = 3; i * i <= n; i += 2 )
            if( n % i == 0 )
                return false;

        return true;
	}
}