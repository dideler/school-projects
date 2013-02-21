/**
 * Binary heap class.
 * The binary heap will be used as a priority queue which holds PrintJobs.
 *
 * More on heaps and binary heaps:
 * http://en.wikipedia.org/wiki/Heap_(data_structure)
 * http://www.ics.uci.edu/~pattis/ICS-23/lectures/notes/Heaps.txt
 * http://en.wikipedia.org/wiki/Binary_heap
 *
 * @author  Dennis Ideler
 * @date    December 2008
 */
 
package printQueue;

import java.lang.RuntimeException;

public class BinaryHeap
{
  private static final int DEFAULT_CAPACITY = 10;  // Default array size.
  private int currentSize;  // Number of current elements in heap.
  private PrintJob[] heap;  // The heap is represented as an array of PrintJobs.

  /******************* NOTES ******************
   * Left child = index * 2
   * Right child = (index * 2) + 1
   * Parent = Math.floor(index / 2)
   *
   * TODO: Decide between currentSize & heap[0]
   ********************************************/

  /**
   * Default constructor calls the custom constructor to build a heap with a
   * a predetermined size.
   */
  public BinaryHeap()
  {
    this(DEFAULT_CAPACITY);
  }


  /**
   * Constructs the binary heap.
   * @param capacity  The capacity of the heap.
   */
  public BinaryHeap(int capacity)
  {
    currentSize = 0;
    heap = new PrintJob[capacity + 1]; // The first index is used for size. TODO: double check
  }


  /**
   * Constructs the binary heap given an array of PrintJobs.
   * Places items into the tree-based data structure (i.e. heap) in any order,
   * maintaining the shape or structure property.
   * Also calls buildHeap() to create a heap-ordered tree.
   *
   * @param jobs  An array of print jobs.
   */
  public BinaryHeap(PrintJob[] jobs)  // TODO does more than initializing; should rename function to "init"
  {
    currentSize = jobs.length;
    heap = new PrintJob[(currentSize + 2) * 11 / 10]; // TODO: find out why I used this size

    int i = 1;
    for (PrintJob job : jobs)  // Copy every printjob into the heap.
      heap[i++] = job;

    buildHeap(); 
  }


  /**
   * Inserts print jobs into the binary heap, satisfying the heap property.
   * To add an element, an up-heap operation must be performed:
   * 1. Add the element to the bottom level of the heap.
   * 2. Compare the added element with its parent; if they are in the correct order, stop.
   * 3. If not, swap the element with its parent and return to the previous step.
   * Has a computational complexity of O(log n).
   *
   * Note: duplicates are allowed.
   * @param newJob  The print job to insert into the heap.
   */
  public void insert(PrintJob newJob)
  {
    if (currentSize == heap.length - 1) // Enlarge heap if full.
      enlargeHeap(heap.length * 2 + 1);

    // New elements are added at the hole. To satisfy the shape property
    // (i.e. complete binary tree), the hole is always at the bottom right.
    int hole = ++currentSize;

    // Now we have to determine where we can insert the new element.
    // We bubble-up its location until we find a valid location.
    // Stop bubbling-up if the added element is in the correct order with its
    // parent (i.e. if we are at the root or root's children, or if added
    // element is less than parent).
    for(; hole > 3 && newJob.compareTo(heap[hole / 2]) < 0; hole /= 2)
      heap[hole] = heap[hole / 2];  // Bubble-up!

    heap[hole] = newJob;  // Place element without violating the heap property.
  }


  /**
   * Removes the root (i.e. minimum element) from the binary heap.
   * To delete the root and restore the heap property, a down-heap operation
   * must be performed:
   * 1. Replace the root of the heap with the last element on the last level.
   * 2. Compare the new root with its children; if they are in the correct order, stop.
   * 3. If not, swap the element with one of its children and return to the previous step.
   *    (Swap with its smaller child in a min-heap.)
   * Has a computational complexity of O(log n).
   *
   * @return  The smallest item (throws exception if empty).
   */
  public void removeMin()
  {
    if (isEmpty())
      throw new RuntimeException("UnderflowException");

    heap[1] = heap[currentSize--];  // Replace root with the last element.
    bubbleDown(1);  // Bubble-down the new root element until it's safe.
  }


  /**
   * Performs a down-heap operation (i.e. swap element with one of its children)
   * until the heap property is satisfied.
   * Note: the function parameter is more important if function was recursive.
   *
   * @param hole  The index at which the down-heap begins.
   */
  private void bubbleDown(int hole)
  {
    int child;  // Index of child.
    PrintJob node = heap[hole];  // The downward-moving node starts at the hole.

    // Need to find a spot for the hole that does not violate heap property.
    // We do that by "bubbling-down" the hole.
    // Note: When swapping nodes during the down-heap operation,
    //       we swap with the smaller child since it's a min-heap.
    while (hole * 2 <= currentSize)  // While we're still in-bounds.
    {
      child = hole * 2;	 // Start with the left child.

      // If left child is not the last child AND if right child is less than left child.
      // i.e. Does the right child exist and is it smaller?
      if (child != currentSize && heap[child + 1].compareTo(heap[child]) < 0)
        child++;  // We should swap the right child.

      // If the child is smaller than the parent, perform the swap.
      // Else we are done with the down-heap operation.
      if (heap[child].compareTo(node) < 0) heap[hole] = heap[child]; //FIXME: shouldn't this compare to the hole?
      else break;

      hole = child;  // Bubble-down the hole.
    }

    heap[hole] = node;  // Safely place the element in the hole.
  }


  /**
   * Finds the smallest item in the binary heap.
   * Because it's a min-heap, the smallest item is the root.
   * Has a computational complexity of O(1).
   *
   * @return  The smallest item (throws exception if empty).
   */
  public PrintJob findMin()
  {
    if (isEmpty())
      throw new RuntimeException("UnderflowException");
    return heap[1];
  }


  /**
   * Checks if the binary heap is (logically) empty.
   *
   * @return  True if empty.
   */
  public boolean isEmpty()
  {
    return currentSize == 0;
  }


  /**
   * (Logically) empties the binary heap.
   */
  public void makeEmpty()
  {
    currentSize = 0;  // FIXME: shouldn't it actually be emptied? otherwise memory leak
  }


  /**
   * Builds the heap while satisfying the heap and shape property.
   * Converts an arbitrary arrangement of elements (i.e. placed in no specific order).
   * Has a complexity of O(n) because it's the sum of all comparisons.
   */
  private void buildHeap()  // aka convertToHeap
  {
    for (int i = currentSize / 2; i > 0; i--) // i starts as parent of last node.
      bubbleDown(i);
  }


  /**
   * Enlarges the array.
   * @param newSize  The new size of the array.
   */
  private void enlargeHeap(int newSize)
  {
    PrintJob[] old = heap;
    heap = new PrintJob[newSize];

    for (int i = 0; i < old.length; i++)
      heap[i] = old[i];
  }


  /**
   * Prints the heap (useful for bugchecking).
   */
  public void printHeap()
  {
    System.out.println();

    for (int i = 0; i < heap.length; i++)
      System.out.println(heap[i]);
    
    System.out.println();
  }

}
