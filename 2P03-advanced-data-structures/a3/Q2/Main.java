/** The implementation of hash tables is called hashing.
  * Hashing is used for performing insertions, deletions, and searches in 
  * constant average time.
  *
  * This program allows you to insert and search for items in a hash table
  * using open addressing for dealing with collisions (i.e. probing hash tables)
  *
  *@author		Dennis Ideler
  *@student#	4134466
  *@course		2P03
  *@assignment	3
  *@question	2															*/

package A3;

import java.io.*;

class Main
{
	BufferedReader br;
//	PrintWriter out;	not sure if needed, not stated in assignment part 2
	LinearProbing hashTable1 = new LinearProbing();
	QuadraticProbing hashTable2 = new QuadraticProbing();
	DoubleHashing hashTable3 = new DoubleHashing();
	
	/** Constructor	*/
	public Main()
	{
		System.out.println("Processing... "+(char)002+"\n"); // happiness message
		
		for(int i = 1; i < 4; i++)	// call process for every probing method
		{
			doProcessing(i); // use with switch case
		}
	}
	
	/** This method does appropriate calls to do everything to construct the 
	 * hash tables.
	 *
	 *@param probeMethod 1: linear, 2: quadratic, 3: double hashing.		*/
	private void doProcessing(int probeMethod)
	{
		try // finding file
		{
			br = new BufferedReader(new FileReader("part2in.txt"));
		//	out = new PrintWriter(new BufferedWriter(new FileWriter("part2out.txt")));
			String [] result;
			String operation = null;
			int item = 0;
			int totInsertCollisions = 0;
			int totSearchCollisions = 0;
			
			try // reading file
			{
				while(br.ready()) // false when all is read
				{
					result = br.readLine().split(" ");  // overwrite string array for every line
														// and split elements based on whitespace 
					operation = result[0];
					if(result.length == 2) item = Integer.parseInt(result[1]);
					
					if(operation.equalsIgnoreCase("quit")) System.out.println(operation);
					else System.out.println(operation+"\t"+item);
					
					switch(probeMethod)
					{
						case 1:	// linear probing
							if(operation.equalsIgnoreCase("insert"))
							{
								hashTable1.insert(item);
								totInsertCollisions += hashTable1.getCollisions();
								displayHashTable("hashTable1");
							}	
							else if(operation.equalsIgnoreCase("search"))
							{
								System.out.println();
								for(int i = 0; i < hashTable1.getTableSize(); i++)
								{
									if(hashTable1.isActive(i)) // check only active cells
									{
										System.out.println("Checking index "+i+"...");
										if(hashTable1.getElement(i) == item) break; // item found, break
									}
								}
								// even though a manual search was already done, still use contains to get #collisions
								if(hashTable1.contains(item)) System.out.println(item+" found!\n");
								else System.out.println(item+" not found.\n");
								totSearchCollisions += hashTable1.getCollisions();
							}
							else if(operation.equalsIgnoreCase("quit"))
							{
								// print number of collision during inserts and searches
								System.out.println("\n# of collisions during inserts: "+totInsertCollisions);
								System.out.println("# of collisions during search: "+totSearchCollisions); 
								return;
							}
							break;
							
						case 2:	// quadratic probing
							if(operation.equalsIgnoreCase("insert"))
							{
								hashTable2.insert(item);
								totInsertCollisions += hashTable2.getCollisions();
								displayHashTable("hashTable2");
							}	
							else if(operation.equalsIgnoreCase("search"))
							{
								System.out.println();
								for(int i = 0; i < hashTable2.getTableSize(); i++)
								{
									if(hashTable2.isActive(i)) // check only active cells
									{
										System.out.println("Checking index "+i+"...");
										if(hashTable2.getElement(i) == item) break; // item found, break
									}
								}
								// even though a manual search was already done, still use contains to get #collisions
								if(hashTable2.contains(item)) System.out.println(item+" found!\n");
								else System.out.println(item+" not found.\n");
								totSearchCollisions += hashTable2.getCollisions();
							}
							else if(operation.equalsIgnoreCase("quit"))
							{
								// print number of collision during inserts and searches
								System.out.println("\n# of collisions during inserts: "+totInsertCollisions);
								System.out.println("# of collisions during search: "+totSearchCollisions); 
								return;
							}
							break;
							
						case 3:	// double hashing
							if(operation.equalsIgnoreCase("insert"))
							{
								hashTable3.insert(item);
								totInsertCollisions += hashTable3.getCollisions();
								displayHashTable("hashTable3");
							}	
							else if(operation.equalsIgnoreCase("search"))
							{
								System.out.println();
								for(int i = 0; i < hashTable3.getTableSize(); i++)
								{
									if(hashTable3.isActive(i)) // check only active cells
									{
										System.out.println("Checking index "+i+"...");
										if(hashTable3.getElement(i) == item) break; // item found, break
									}
								}
								// even though a manual search was already done, still use contains to get #collisions
								if(hashTable3.contains(item)) System.out.println(item+" found!\n");
								else System.out.println(item+" not found.\n");
								totSearchCollisions += hashTable3.getCollisions();
							}
							else if(operation.equalsIgnoreCase("quit"))
							{
								// print number of collision during inserts and searches
								System.out.println("\n# of collisions during inserts: "+totInsertCollisions);
								System.out.println("# of collisions during search: "+totSearchCollisions); 
								return;
							}
							break;
							
						default:
							System.out.println("\nInvalid probe method!\n");
							break;
					}
				}
			}
			catch(IOException e){ System.out.println("\nFile input error!\n"); }
			
			finally // ensures the closing of resources
			{
	      		if (br != null /*|| out != null*/)
	      		{
	      			try 
	      			{ 
	      				br.close();
	      			//	out.close();
	      				switch(probeMethod)
	      				{
	      					case 1:
	      						System.out.println("\nLinear Probing hash table completed!\n");
	      						break;
	      					case 2:
	      						System.out.println("\nQuadratic Probing hash table completed!\n");
	      						break;
	      					case 3:
	      						System.out.println("\nDouble Hashing hash table completed!\n");
	      						break;
	      				}
	      				System.out.println("===========================================\n");
	      			}
	        		catch(Exception e) { }
	      		}
	    	}
		}
		catch(FileNotFoundException e){System.out.println("\nFile not found!\n");}
 		catch(IOException e){System.out.println("\nFile output error!\n");}
	}
	
	
	/** Display the hash table along with its content
* UPDATE: USE HASHTABLE AS PARAMATER INSTEAD OF STRING, will get rid of repeat code!
	 *@param hashTable the hash table you wish to display.		*/
	private void displayHashTable(String hashTable)
	{
		int i = 0;
		System.out.println();
		
		// display linear probing hash table
		if(hashTable.equalsIgnoreCase("hashTable1"))
		{
			// display positions
			for(; i < hashTable1.getTableSize() + 1; i++)
				System.out.print(i+" ");
			System.out.println();
			
			// display content at positions
			for(i = 0; i < hashTable1.getTableSize(); i++)
			{
				if(hashTable1.isActive(i))
					System.out.print(hashTable1.getElement(i)+" ");
				else
				{
					if(i < 10) System.out.print("  "); // numbers 0-9 require 2 whitespaces
					else System.out.print("   "); // numbers 10+ require 3 whitespaces
				}
			}
			System.out.println("\n");
			return;
		}
		
		// display quadratic probing hash table
		if(hashTable.equalsIgnoreCase("hashTable2"))
		{
			// display positions
			for(; i < hashTable2.getTableSize() + 1; i++)
				System.out.print(i+" ");
			System.out.println();
			
			// display content at positions
			for(i = 0; i < hashTable2.getTableSize(); i++)
			{
				if(hashTable2.isActive(i))
					System.out.print(hashTable2.getElement(i)+" ");
				else
				{
					if(i < 10) System.out.print("  ");
					else System.out.print("   ");
				}
			}
			System.out.println("\n");
			return; 
		}
		
		// display double hashing table
		if(hashTable.equalsIgnoreCase("hashTable3"))
		{
			// display positions
			for(; i < hashTable3.getTableSize() + 1; i++)
				System.out.print(i+" ");
			System.out.println();
			
			// display content at positions
			for(i = 0; i < hashTable3.getTableSize(); i++)
			{
				if(hashTable3.isActive(i))
					System.out.print(hashTable3.getElement(i)+" ");
				else
				{
					if(i < 10) System.out.print("  ");
					else System.out.print("   ");
				}
			}
			System.out.println("\n");
			return;
		}
	}
	
	public static void main(String[]args){new Main();}
}