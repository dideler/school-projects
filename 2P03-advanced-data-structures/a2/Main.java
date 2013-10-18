/** Main file
 *
 * program is run from this file.
 *
 *@author		Dennis Ideler
 *@student#		4134466
 *@assignment	2
 *@due date		Nov. 10 2008	(extension Nov.12)					*/
 
package A2;
import java.io.*;
import java.util.Stack;
import java.util.Arrays;

class Main
{
	BufferedReader br;
	BST tree, reverseTree1, reverseTree2;
//	PrintWriter out;
	int countNodes;
	
	public Main() throws FileNotFoundException
	{
		System.out.println("Processing... "+(char)002); // happiness message
		generateTree();
	}
	/** Method which reads in a list from an input file, and adds the 3 digit
	  * integers to a node to create a binary search tree
	  *> Done using the split method of String.
	  *
	  *@throws FileNotFoundException if the input file is not found.
	  *@catches NumberFormatException if string cannot be converted to an int.
	  *@catches IOException if non standard input or output occurs.			*/
	public void generateTree() throws FileNotFoundException
	{
		try // try finding file
		{
			String[] result;
			br = new BufferedReader(new FileReader("input.txt"));
			int numTrees = 1;
			
			try // try reading in file
			{	
				while(br.ready()) // false when all is read
				{	
					int digits[] = new int [250]; // initialize big to be safe, although empty spaces is wasted resources
					int digit = 0; // reset digit for every tree
					countNodes = 0; // reset node count for every tree
					tree = new BST(); // create new tree for every line in file
					reverseTree1 = new BST(); // -"-
					reverseTree2 = new BST(); // -"-
					
					System.out.println("\n-------------Tree #"+numTrees+"---------------\n");
					
					result = br.readLine().split(",");
			     	
			     	for (int i=0; i<result.length; i++)
			        try // try parsing int to string
			        {
			        	digit = Integer.parseInt(result[i]);
				    	if(digit > 99 && digit < 1000)
				    	{
				    		digits[i] = digit;
				    		tree.insert(digit);
				    		reverseTree1.reverseInsertRecursive(digit);
					   		countNodes++;
				    	}
				    	else System.out.println("Invalid input. Skipped: "+digit);
				    }
			        catch(NumberFormatException e)
			        {
			        	System.out.println("Invalid input. Skipped: "+result[i]);
			        	digit = 0;
			        }
			        
			        reverseTree2 = reverseInsertIter(preorderArray(reverseTree1.root));
			        System.out.println(reverseTree2.root);
			        
			     /***---choose tree and printing method here---***/
			     
			     // some examples given or used for testing....
			     
			     // tree.visualize();
			     
			     //	System.out.println("\nCompleted tree:")
			     //	createCompleteTree(tree).vsualize();
			     	
			     // System.out.println("\nMirrored tree:");
			     // reverseTree1.visualize();
			        
			     // System.out.println("\nReverse the mirrored tree:");
			     // reverseTree2.visualize(); almost works!
			       
			        tree.printTree("breadthFirst");
			        
			        System.out.println("\nCompleted tree:");
			        createCompleteTree(tree).printTree("breadthFirst");
			        
			        System.out.println("\nMirrored tree:");
			        reverseTree1.printTree("breadthFirst");
			        
			        System.out.println("\nReverse the mirrored tree:");
			        reverseTree2.printTree("breadthFirst");
			        
			        System.out.println("\nMin = "+tree.findMin());
			        System.out.println("\nMax = "+tree.findMax());
			        System.out.println("\nOriginal height = "+ tree.height());
			        System.out.println("Is original tree full? "+tree.isFull());
			        System.out.println("Is original tree complete? "+tree.isComplete());
			      /***--------------------------------------------***/
			        countNodes();
			        countNullPtrs();
			        numTrees++;
				}
				System.out.println("-----------------------------------\n\nDone processing! "+(char)002+"\n");
			}
			catch(IOException e){ System.out.println("\nFile input error!\n"); }
			
			finally // ensures the closing of resources
			{
	      		if (br !=null)
	      		{
	      			try { br.close(); }
	        		catch(Exception e) { } 
	      		}
	    	}
		}
		catch(FileNotFoundException e){ System.out.println("\nFile not found error!\n");}
	}
	
	/** Method to count the nodes in a tree.
	  *> prints out the counter that keeps track of amount of nodes. 	*/
	private void countNodes()
	{ System.out.println("\n# of nodes: "+countNodes); }
	
	/** Method to count the null pointers in a tree.
	  *> if tree has no nodes, then 0 nullpointers.
	  *> else, nullpointers = nodes + 1.						*/
	private void countNullPtrs()
	{ 
		if(countNodes == 0)	System.out.println("# of null ptrs: 0\n");
		else System.out.println("# of null ptrs: "+(countNodes+1)+"\n");
	}
	
	 /** Method to put the preorder traversal of a tree into an array.
	   * This way, I can take the preorder of the reversed tree,
	   * and using that preorder as input, reverse the tree again to it's
	   * initial state.
	   *> Uses the iterative preorder traversal, because if you use the
	   *> recursive method, your objects and variables will be initialized every
	   *> time the recursive call is made. This is bad.
	   *> Cannot solve it by using global initialization, because then you can
	   *> not initialize for every new tree.
	   *
	   *@param t the node that roots the subtree.							*/
	 private int [] preorderArray(BinaryNode<Integer> t)
	 {
	 	Stack stack = new Stack();	 	
	 	int []treeArray = new int[250];
	 	int index = 0;
	 	
	 	while(t!=null)
	 	{
	 		treeArray[index] = t.element;
	 		index++;
	 		
	 		if(t.right!=null) stack.push(t.right);
	 		if(t.left!=null) t = t.left;
	 		else if(!stack.empty()) t = (BinaryNode<Integer>)stack.pop();
	 		else t = null;
	 	}
	 	return treeArray;
	 }
	 
	 /** Method to reverse-insert using the digits from the reversed tree
	   * which are stored in an array in preorder order.
	   *> This method uses the array returned from preorderArray().
	   *
	   *@param array the array with digits that it will use to "reverse insert" into a new tree */
	 private BST reverseInsertIter(int [] array)
	 {
	 	int x = 0; // indexer for array
	 	BST temp = new BST();
			        
		while(array[x]!=0) // while array still has digits in it
		{
		   	temp.reverseInsertIterative(array[x]); // insert the preorder of the reverse tree
		   	x++;
		}
		return temp;
	 }
	 
	 /** Method to create a complete tree.
	   *> Rearranges input to create the complete tree.
	   *> Sorts the list of digits. Get root using method below. Then create 2
	   *> lists. One containing digits less than root, and one with greater.
	   *> For each insert, take the sum of digits you are dealing with 
	   *> divided by the number of digits you are dealing with, round the 
	   *> answer and check what digit in the list, the answer is closest to.
	   *> This is the digit you will insert. Repeat...
	   *
	   *@param t the binary search tree which you have to completed.		 */
	 private BST createCompleteTree(BST t)
	 {
	 	if(t.root!=null)
	 	{	
		 	if(!t.isComplete())
		 	{
		 		int [] inorderArray = new int[countNodes];
		 		int [] smaller = new int[80];
				int [] greater = new int[80];		 		
			 	double sum = 0;
			 	int digit = 0;
			 	int closestDigit = 0;
			 	int minDelta = 1000;
			 	BST compTree = new BST();
			 	int i, j, n, r, root;
			 	
		 		// copy the preorderArray to the inorderArray
		 		System.arraycopy(preorderArray(t.root),0,inorderArray,0,countNodes);
		 		Arrays.sort(inorderArray);
		 		
		 		for(i = 0; i < countNodes; i++)
		 		{
		 			sum += inorderArray[i];
		 		}
		 		
		 		digit = (int) Math.round(sum/countNodes);
		 		
		 		for(j = 0; j < countNodes-1; j++) // find integer in list nearest to digit
		 		{
		 			int temp = Math.abs(inorderArray[j] - digit);
		 			if(temp < minDelta || temp == 0)
		 			{
		 				minDelta = temp;
		 				closestDigit = j;
		 			}
		 		}
		 		compTree.insert(inorderArray[closestDigit]); // inserts the root
		 		root = closestDigit;
		 		//------------------------------------------------------------// END OF INSERTING ROOT
		 		
		 		countNodes = 0; // reset node count for the following array
		 		sum = 0;		// reset sum for the following array
		 		minDelta = 1000;// reset min for the following array
		 		
		 		// insert digits into smaller than root array
		 		for(int k = 0; k < root; k++)
		 		{
		 			smaller[k] = inorderArray[k];
		 			countNodes++;
		 		}
		 		
		 		int repeat = countNodes;
		 		
		 		// repeat insertion process for smaller than root digits
		 		for(int l = 0; l < repeat; l++)
		 		{
		 			for(int m = 0; m < countNodes; m++)
			 		{
			 			sum += smaller[m];	// calculate sum
			 		}
			 		
			 		digit = (int) Math.round(sum/countNodes);
			 		
			 		for(n = 0; n < countNodes-1; n++) // find integer in list nearest to digit
			 		{
			 			int temp = Math.abs(smaller[n] - digit);
			 			if(temp < minDelta || temp == 0)
			 			{
			 				minDelta = temp;
			 				closestDigit = n;
			 			}
			 		}
			 		
			 		if(countNodes == 1) compTree.insert(smaller[0]);
			 		else compTree.insert(smaller[closestDigit]);
			 		//-----------------------------------------------//
			 		int [] temp = new int[50];
			 		System.arraycopy(smaller,0,temp,0,countNodes);
			 		
			 		sum = 0;
			 		countNodes--;
			 		
			 		Arrays.fill(smaller,0); // clear array
			 		int indexTemp = 0;
			 		
			 		for(int lol = 0; lol < countNodes; lol++)
			 		{
			 			if(lol == closestDigit) indexTemp++;
			 			smaller[lol] = temp[indexTemp];
			 			indexTemp++;
			 		}
		 		}
		 		
		 		//------------------------------------------------------------// END OF INSERTING INTO LEFT SUBTREE
		 		
		 		countNodes = 0; // reset node count for the following array
		 		sum = 0;		// reset sum for the following array
		 		minDelta = 1000;// reset min for the following array
		 		int indx = 0;
		 		
		 		// insert digits into greater than root array
		 		for(int o = root+1; o < j+1; o++)
		 		{
		 			greater[indx] = inorderArray[o];
		 			countNodes++;
		 			indx++;
		 		}
		 		System.out.println();
		 		
		 		int repeat2 = countNodes;
		 		
		 		// repeat insertion process for greater than root digits
		 		for(int p = 0; p < repeat2; p++)
		 		{
		 			for(int q = 0; q < countNodes; q++)
			 		{
			 			sum += greater[q];	// calculate sum
			 		}
			 		
			 		digit = (int) Math.round(sum/countNodes);
			 		
			 		for(r = 0; r < countNodes-1; r++) // find integer in list nearest to digit
			 		{
			 			int temp = Math.abs(greater[r] - digit);
			 			if(temp < minDelta || temp == 0)
			 			{
			 				minDelta = temp;
			 				closestDigit = r;
			 			}
			 		}
			 		if(countNodes == 1) compTree.insert(greater[0]);
			 		else compTree.insert(greater[closestDigit]);
			 		//-----------------------------------------------//
			 		int [] temp = new int[50];
			 		System.arraycopy(greater,0,temp,0,countNodes);
			 		
			 		sum = 0;
			 		countNodes--;
			 		
			 		Arrays.fill(greater,0); // clear array
			 		int indexTemp2 = 0;
			 		
			 		for(int brb = 0; brb < countNodes; brb++)
			 		{
			 			if(brb == closestDigit) indexTemp2++;
			 			greater[brb] = temp[indexTemp2];
			 			indexTemp2++;
			 		}
		 		}
		 		return compTree;
		 	}
	 	}
	 	return t;
	 }
	 
	  
	/*public void createFile() throws IOException // don't forget to CLOSE resources!
	 {
	    out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
	    out.print(123); // testing
	    out.close();
	    //System.out.println("\nYour file has been written");
	 }*/
	 
	public static void main(String[]args)throws FileNotFoundException{new Main();}
}