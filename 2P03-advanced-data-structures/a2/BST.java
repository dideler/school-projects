/** Binary Search Tree class
 *
 *@author		Dennis Ideler
 *@student#		4134466
 *@assignment	2
 *@due date		Nov. 10 2008		(Extension Nov.12)					*/

/******************************************************************************
 * RETURN STRING FOR EVERY TRAVERSAL, SO THAT THE ONLY PRINTING HAPPENS IN MAIN
 * DO NOT USE PRINTWRITER IN THIS CLASS!
 ******************************************************************************/
package A2;
import java.io.*;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Queue;

public class BST<Integer extends Comparable<? super Integer>> 
{	 
	 BinaryNode<Integer> root;
	 Queue queue;
	 private Main file;
	 
	 public BST()
	 { 	root = null; } // constructor
	 
	 public void makeEmpty()
	 { 	root = null; }
	 
	 public boolean isEmpty()
	 { 	return root == null; }
	 
	 public boolean isFull()
	 {	return isFull(root); }
	 
	 public boolean isComplete()
	 {	return isComplete(root); }
	 
	 public boolean contains(Integer x)
	 {	return contains(x, root); }
	 
	 public Integer findMin()
	 {
	 	if(isEmpty()) return null;
	 	return findMin(root).element;
	 }
	 
	 public Integer findMax()
	 {
	 	if(isEmpty()) return null;
	 	return findMax(root).element;
	 }
	 
	 public void reverseInsertRecursive(Integer x)
	 {	root = reverseInsertRecursive(x,root); }
	 
	 public void reverseInsertIterative(Integer x)
	 {	root = reverseInsertIter(x,root); }
	 
	 public void insert(Integer x)
	 { 	root = insert(x,root);	}
	 
	 public void remove(Integer x)
	 {	root = remove(x,root);	}
	 
	 public int height()
	 { 	return height(root); }
	 
	 public void simpleVisualize()
	 {	simpleVisualize(root); }
	 
/*	 public void visualize()
	 {	visualize(root); } */
	 
	 public void printTree(String traversal)
	 {
	 	if(isEmpty())
	 		System.out.println("\nUnderflow Err: Empty tree (empty input line or no valid entries in line)\n");
	 	
	 	else if(traversal.compareToIgnoreCase("preorder") == 0)
	 	{
	 		System.out.println("\nPreorder traversal:\n");
	 		preorder(root);
	 	}
	 	else if(traversal.compareToIgnoreCase("inorder") == 0)
	 	{
	 		System.out.println("\nInorder traversal:\n");
	 		inorder(root);	
	 	}
	 	else if(traversal.compareToIgnoreCase("postorder") == 0)
	 	{
	 		System.out.println("\nPostorder traversal:\n");
	 		postorder(root);
	 	}
	 	else if(traversal.compareToIgnoreCase("breadthfirst") == 0)
	 	{
	 		System.out.println("\nBreadth First traversal:\n");
	 		breadthFirst(root);
	 	}
	 	else System.out.println("\nprintTree() Err: Valid parameters are 'preorder', 'inorder', 'postorder'\n");
	 }
	 
	 /**************************** NOTES ***************************************
	  * 1) two items are equal iff compareTo returns 0 
	  * 2) ? : is shorthand for an if-else statement (one line conditional)
	  * 	example-> var = (statement) ? x : y
	  * 	if statement is true, then var = x, else var = y
	  *	3) for a quick & complete built-in preorder traversal, print out the root
	  **************************************************************************/
	 
	 /** Method to determine whether a tree is full or not
	   *> Full if every node, except leaves, has exactly 2 children.
	   *>> Uses breadth-first traversal to spot missing children.
	   *
	   *@param t the node that roots the subtree.						
	   *@return true if tree is full, false otherwise.					*/
	 private boolean isFull(BinaryNode<Integer> t)
	 {	
	 	queue = new LinkedList();
	 	BinaryNode<Integer> temp;
	 	
	 	if(t != null) queue.add(t);	// insert the root node into the queue
	 	else return false;					// tree does not exist
	 	
	 	while(!queue.isEmpty())
	 	{
	 		temp = (BinaryNode<Integer>) queue.remove();	// temp holds parent
	 		
	 		if(temp.left == null && temp.right != null) return false; // missing left child
	 		if(temp.left != null && temp.right == null) return false; // missing right child
	 		
	 		if(temp.left!=null) queue.add(temp.left);	// add left child to queue
	 		if(temp.right!=null) queue.add(temp.right);	// add right child to queue
	 	}
	 	
	 	return true;
	 }
	 
	 /** Method to determine whether a tree is full or not
	   *> Complete if each node that has a right child also has a left child.
	   *> (Definition taken from Wikipedia) 
	   *> To some terminology: "Almost Complete" = Complete, "Complete" = Full
	   *> A full tree is a complete tree, but not vice versa.
	   *> Uses breadthfirst traversal to traverse through nodes.
	   *
	   *@param t the node that roots the subtree.
	   *@return true if tree is complete, false otherwise.			*/
	 private boolean isComplete(BinaryNode<Integer> t)
	 {	
	 	if(t!=null)
	 	{
	 		if(isFull()) return true; // a full tree is always complete
	 		else
	 		{
	 			queue = new LinkedList();
			 	BinaryNode<Integer> temp, temp2;
			 	
			 	queue.add(t);	// insert the root node into the queue
			 	temp2 = null;
			 	
			 	while(!queue.isEmpty())
			 	{
			 		temp = (BinaryNode<Integer>)queue.remove();	// temp becomes first in line
			 		if(temp.left!=null) queue.add(temp.left);	// add left child to queue
			 		if(temp.right!=null) queue.add(temp.right);	// add right child to queue
			 		temp2 = temp;
			 		
			 		//check for leaves that are above height = 1
				 	if(height(temp) != 1 && height(temp) != 0)
				 	{
				 		// it it's a leaf
				 		if(temp.left == null && temp.right == null) return false;
				 	}
				 	
				 	// check for a leaf on the last level that isn't leftmost
				 	if(height(temp)==1)
				 	{
				 		// if node has a right child and no left child
				 		if(temp.left==null && temp.right!=null) return false;
				 	}
			 	}	
	 		}
		 	return true; // if no violations found, then it's complete
		 }
	 	return false; // if empty tree, then not complete
	 }
	 
	 /** Recursive method to find an item in a subtree
	   *> If tree is empty, return false. Else, make a recursive call on the 
	   *> subtree of T, either left or right, depending on the relationship
	   *> of X to the item stored in T.
	   *
	   *@param x is item to search for.
	   *@param t the node that roots the subtree.
	   *@return node contaning the matched item.						*/
	 private boolean contains(Integer x, BinaryNode<Integer> t)
	 {
	 	if(t==null) return false; // if tree is empty, return false
	 	
	 	int compareResult = x.compareTo(t.element);
	 	
	 	if(compareResult < 0) return contains(x, t.left); // if smaller
	 	else if(compareResult > 0) return contains(x, t.right); //if larger
	 	else return true; // found a match
	 }
	 
	 /** Recursive method to find smallest item in a subtree
	   *> Start at root and go left until you reach a leaf
	   *
	   *@param t the node that roots the subtree.
	   *@return node containing the smallest item.				*/
	 private BinaryNode<Integer> findMin(BinaryNode<Integer> t)
	 {
	 	if(t==null) return null;
	 	else if(t.left==null) return t;
	 	return findMin(t.left);
	 }
	 
	 /** Nonrecursive method to find largest item in a subtree
	   *> Start at root and go right until you reach a leaf
	   *
	   *@param t the node that roots the subtree.
	   *@return node containing the largest item.				*/
	 private BinaryNode<Integer> findMax(BinaryNode<Integer> t)
	 {
	 	if(t!=null)
	 	{
	 		while(t.right!=null) t=t.right;
	 	}
	 	return t;
	 }
	 
	 /** Recursive method to insert X into a subtree
	   *> Proceed down the tree as you would in contains().
	   *> If X is found (thus a duplicate case), throw an exception (or do
	   *> nothing). Else, insert X at the last spot on the path traversed.
	   *
	   *@param x the item to insert.
	   *@param t the node that roots the subtree.
	   *@return the new root of the subtree.					*/
	 private BinaryNode<Integer> insert(Integer x, BinaryNode<Integer> t)
	 {
	 	if(t==null) return new BinaryNode<Integer>(x,null,null);
	 	
	 	int compareResult = x.compareTo(t.element);
	 	
	 	if(compareResult < 0) t.left = insert(x,t.left); // if smaller
	 	else if(compareResult > 0) t.right = insert(x,t.right); // if larger
	 	else System.out.println("Duplicate Err: "+x.toString()); // duplicate
	 	
	 	return t;
	 }
	 
	 /** Recursive method to remove from a subtree
	   *> If the node is a leaf, it can be deleted immediately.
	   *> Else if the node has one child, the node can be deleted after its
	   *> parent adjusts a link to bypass the node.
	   *> Else if the node has two children, replace its data with the smallest 
	   *> data of the right subtree (because that node cannot have a left child)
	   *> and (recursively) delete that node (which is now empty).
	   *
	   *@param x the item to remove.
	   *@param t the node that roots the subtree.
	   *@return the new root of the subtree.					*/
	 private BinaryNode<Integer> remove(Integer x, BinaryNode<Integer> t)
	 {
	 	if(t==null) return t; // item not found (tree non-existant), does nothing
	 	
	 	int compareResult = x.compareTo(t.element);
	 	
	 	if(compareResult < 0) t.left = remove(x,t.left); // if x is smaller
	 	else if(compareResult >0) t.right = remove(x,t.right); // if x is larger
	 	else if(t.left!=null && t.right!=null) // if node has two children
	 	{
	 		// replace data with data of the smallest node of the right subtree
	 		t.element = findMin(t.right).element;
	 		
	 		// remove the node which the data was just taken from
	 		t.right = removeMin(t.right);
	 		
	 		// OR t.right = remove(t.element, t.right) if you want to delete that node recursively
	 	}
	 	// if left child exists, current node becomes left child, else becomes right child
	 	else t = (t.left!=null) ? t.left : t.right; 
	 	return t;
	 }
	 
	 /** Recursive method to remove the minimum item of a subtree
	   *
	   *@param t the node that roots the subtree.
	   *@return the new root of the subtree.								*/
	 private BinaryNode<Integer> removeMin(BinaryNode<Integer> t)
	 {
	 	if(t==null) return t;	// item is non-existant
	 	else if(t.left!=null)
	 	{
	 		t.left = removeMin(t.left);
	 		return t;
	 	}
	 	else return t.right;
	 }
	 
	 /** Recursive method to determine the height of a tree
	   *> Takes the maximum height of the two subtrees and adds 1
	   *
	   *@param t the node that roots the subtree.
	   *@return the height of the (sub)tree.					*/
	 private int height(BinaryNode<Integer> t)
	 {
	 	if(t==null) return -1;
	 	else return 1 + Math.max(height(t.left),height(t.right));
	 }
	 
	 
	 /** Recursive method for preorder traversal
	   *> visit, left, right
	   *
	   *@param t the node that roots the subtree.		*/
	 private void preorder(BinaryNode<Integer> t)
	 {
	 	if(t!=null)
	 	{
	 		System.out.println(t.element);
	 		
	 		if(t.left==null && t.right==null) System.out.println("is a leaf");
	 		else if(t.left==null) System.out.println("left child = null");
	 		else if(t.right==null) System.out.println("right child = null");
	 		if(t.left!=null) System.out.println("left child = "+t.left.element);
	 		if(t.right!=null) System.out.println("right child = "+t.right.element);
	 		
	 		preorder(t.left);
	 		preorder(t.right);
	 	}
	 }
	 
	 /** Recursive method for inorder traversal (will be in sorted order)
	   *> left, visit, right
	   *
	   *@param t the node that roots the subtree			*/
	 private void inorder(BinaryNode<Integer> t)
	 {
	 	if(t!=null)
	 	{
	 		inorder(t.left);
	 		System.out.println(t.element);
	 		inorder(t.right);
	 	}
	 }
	 
	 /** Recursive method for postorder traversal
	   *> left, right, visit
	   *
	   *@param t the node that roots the subtree				*/
	 private void postorder(BinaryNode<Integer> t)
	 {
	 	if(t!=null)
	 	{
	 		postorder(t.left);
	 		postorder(t.right);
	 		System.out.println(t.element);
	 	}
	 }
	 
	 /** Method for Breadth-first traversal
	   *> Traverses each level one by one, left to right.
	   *> Uses a queue, thus FIFO.
	   *
	   *@param t the node that roots the subtree				*/
	 private void breadthFirst(BinaryNode<Integer> t)
	 {
	 	queue = new LinkedList();
	 	BinaryNode<Integer> temp;
	 	
	 	queue.add(t);	// insert the root node into the queue
	 	
	 	while(!queue.isEmpty())
	 	{
	 		temp = (BinaryNode<Integer>)queue.remove();	// temp becomes first in line
	 		if(temp.left!=null) queue.add(temp.left);	// add left child to queue
	 		if(temp.right!=null) queue.add(temp.right);	// add right child to queue
	 		System.out.println(temp.element/*+" height = "+height(temp)*/); // height used to bugcheck
	 	}
	 }
	 
	 /** Method to visualize the tree.
	   *> Start simple, and then improve once it works.
	   *
	   *@param t the node that roots the subtree.				*/
	 private void simpleVisualize(BinaryNode<Integer> t)
	 {
	 	queue = new LinkedList();
	 	BinaryNode<Integer> temp, temp2;
	 	
	 	System.out.println("\nPre: "+t);	 	// prints the built-in preorder traversal
	 	
	 	int maxWidth = (int) Math.pow(2,height());
	 	
	 	if(t!= null)
	 	{
		 	queue.add(t);
		 	temp2 = null;
			
		 	while(!queue.isEmpty())
		 	{
		 		temp = (BinaryNode<Integer>)queue.remove();	// temp becomes first in queue line
				
		 		if(temp.left!=null)	queue.add(temp.left);	// add left child to queue
		 		if(temp.right!=null) queue.add(temp.right);	// add right child to queue

		 		if(height(temp) != height(temp2)) System.out.println(); // if not on same level, skip line
		 		System.out.print(temp.element+" ");
		 		temp2 = temp;	// temp2 holds the "old" node that temp was
		 	}
		 	System.out.println();
	 	}
	 }
	 
	 /** Method to visualize tree.
	   *> Use a list that has the nodes stored in breadthfirst traversal, 
	   *> along with the height of each node.
	   *
	   *@param t the node that roots the subtree.				*/
/*	 private void visualize(BinaryNode<Integer> t)
	 {
	 	int maxwidth = Math.pow(2,height(t));
	 	
	 	for(int i = 0; i < height(t)+1; i++) // repeat for every line in tree
	 	{
	 		//nodeline code
	 		int w, innerw; // w = whitespaces, d = dashes, innerw = inner w
	 		int d = maxwidth - 2;
	 		int b = 1;
	 		
	 		for(int a = 0; a< height(t)+1; i++) // calculate w
	 		{
	 			w = maxwidth / j;
	 			if(a == height(t)) w = 0;
	 			b *= 2;
	 		}
	 		
	 		for(int c = 0; c < height(t)-1; c++) // dashes go until 3rd lvl from bottom
	 		{
	 			d = (d/2)-1;
	 		}
	 		
	 		for(int e = 0; e < height(t)+1; e++) // calculate innerw
	 		{
	 			if(e == 1) innerw = maxwidth+1;
	 			innerw = (int) Math.ceil(innerw/2);
	 			if(e == height(t)) innerw = 1; // bottom level
	 		}
	 		
	 		for(int j = 0; i != w; i++)
	 		{
	 			System.out.print(" "); // print whitespaces
	 		}
	 		
	 		for() // repeat for each node on level
	 		{
		 		for(int k = 0; k != d; k++)
		 		{
		 			System.out.print("-"); // print dashes
		 		}
		 		
		 		/*** print current node ***/
		 		
/*		 		for(int l = 0; l != d; l++)
		 		{
		 			System.out.print("-"); // print dashes
		 		}
		 		
		 		for(int m = 0; m != innerw; m++)
		 		{
		 			System.out.print(" "); // print inner whitespaces
		 		}
	 		}
	 		
	 		System.out.println();
	 		//----------------------------------------------------------------//
	 		if(i == height(t)) break; // if bottom level
	 		
	 		//slashline code
	 		int w2 = maxwidth - 1;
	 		int innerw2 = (maxwidth*2) - 1;
	 		
	 		for(int z = 0; z < height(t); z++) // calculate whitespaces
	 		{
	 			w2 = w2 / 2; // discards the fraction, integer division
	 		}
	 		
	 		for(int y = 0; y < height(t); y++) // calculate inner whitespaces
	 		{
	 			innerw2 = innerw2 / 2;	// discards the fraction, int division
	 		}
	 		
	 		for(int x = 0; x != w2; x++) // print whitespaces
	 		{
	 			System.out.print(" ");
	 		}
	 		
	 		for(int w = 0; .... ) // repeat for every node on next level
	 		{
	 			char slash = '/';
	 			if(w % 2 ==  1) slash = '\';
	 			
	 			System.out.print(slash); // print slash
	 			
	 			if(w == nodes on next level) break; // prevents printing of extra spaces
	 			
	 			for(int s = 0; s != innerw2; s++) // print inner whitespaces
	 			{
	 				System.out.print(" ");
	 			}
	 		}
	 		
	 		System.out.println();
	 	}
	 } // WORK STILL IN PROGRESS, USE SIMPLE VISUALIZATION FOR NOW
	 
	 /** Method to reverse the tree (mirror the tree) recursively.
	   *> Similar to insert(), but in this case
	   *> n.left.value > n.value > n.right.value
	   *
	   *@param x the digit to insert.
	   *@param t the node that roots the subtree.
	   *@return the new root of the subtree.					*/
	 private BinaryNode<Integer> reverseInsertRecursive(Integer x, BinaryNode<Integer> t)
	 {
	 	if(t==null) return new BinaryNode<Integer>(x,null,null);
	 	
	 	int compareResult = x.compareTo(t.element);
	 	
	 	if(compareResult < 0) t.right = reverseInsertRecursive(x,t.right); // if smaller
	 	else if(compareResult > 0) t.left = reverseInsertRecursive(x,t.left); // if larger
	 	else System.out.println("Duplicate Err: "+x.toString()); // duplicate
	 	return t;
	 }
	 
	 
	 /** Method to reverse the tree (mirror the tree) iteratively.
	   *
	   *@param x the digit to insert.
	   *@param t the node that roots the subtree.
	   *@return the new root of the subtree.								*/
	 private BinaryNode<Integer> reverseInsertIter(Integer x, BinaryNode<Integer> t)
	 {
     	if (t == null)
     	{
     		t = new BinaryNode<Integer>(x,null,null);
     		return t;
     	}
     	
        else
        {
        	while (t != null) // search for leaf
        	{
            	if (x.compareTo(t.element) < 0) // insert on right
            	{
                    if (t.right == null) // when at end of tree, insert
                    {
                    	t.right = new BinaryNode<Integer>(x,null,null);
                    	return t;
                    }
                    else t = t.right; // not at end of tree, move right in tree and continue search   
                }
                
                else if(x.compareTo(t.element) > 0) // insert on left
                {
                	if (t.left == null) // when at end of tree, insert
                	{
                		t.left = new BinaryNode<Integer>(x,null,null);
                		return t;
                    }
                    else t = t.left; // not at end, move left in tree and continue search
                }
                
                else System.out.println("Duplicate Err: "+x.toString()); // duplicate
            }
        }
      	return t;
    } // has a bug, try and fix
	
}