/** HashEntry class
  *> The entry cell for the hash table array with entry cells
  *
  *@author		Dennis Ideler
  *@student#	4134466
  *@course		2P03
  *@assignment	3
  *@question	2															*/

package A3;

public class HashEntry
{
	public int element;	// the element in the entry
	public boolean isActive;	// false when marked as deleted, lazy deletion
	
	// constructor 1
	public HashEntry(int item)
	{	this(item, true);	}
	
	// constructor 2
	public HashEntry(int item, boolean boolActive)
	{
		element = item;
		isActive = boolActive;
	}
}