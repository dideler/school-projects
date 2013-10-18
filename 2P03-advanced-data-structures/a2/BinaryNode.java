/** BinaryNode class
 *
 * for this assignment, each node will hold a 3-digit integer (100-999)
 *
 *@author		Dennis Ideler
 *@student#		4134466
 *@assignment	2
 *@due date		Nov. 10 2008	(Extension Nov.12)						*/
 
package A2;

public class BinaryNode<Integer>
{
	BinaryNode(Integer theElement, BinaryNode<Integer> left, BinaryNode<Integer> right)
	{
		element = theElement;
		left = right = null;
	} // constructor
	
	// friendly data
	Integer element;	// the data in the node
	BinaryNode left;	// left child
	BinaryNode right;	// right child
	
	// returns node as a string; useful for bugchecking (just print out node to use)
	public String toString()
	{
		return element+"_"+left+"_"+right;
	}
}