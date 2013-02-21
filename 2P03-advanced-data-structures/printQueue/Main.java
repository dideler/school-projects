/**
 * A simple priority queue [1] that acts as a printing queue for a hypothetical
 * printer. The priority queue is implemented as a min-heap, which is basically
 * a binary heap with a "less than or equal to" comparison function [2].
 * 
 * [1] http://en.wikipedia.org/wiki/Priority_queue
 * [2] http://en.wikipedia.org/wiki/Binary_heap
 *
 * @author  Dennis Ideler
 * @date    December 2008
 */

package printQueue;

import java.io.*;

class Main
{
  BinaryHeap heap;
  PrintJob job;

  int id;
  int arrivalTime;
  int numPages;
  String inkType;
  int index = 0;
  int timer = 0;

  public Main()
  {
    System.out.println("Processing... ");
    readFile();
  }


  /**
   * Reads the file containing the input data and creates new print jobs.
   */
  private void readFile()
  {
    try  // Try finding the file.
    {
      BufferedReader br = new BufferedReader(new FileReader("input.txt"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
      heap = new BinaryHeap();

      try  // Try reading and parsing the file.
      {
        while (br.ready())
        {
          String[] line = br.readLine().split(" ");
          id = Integer.parseInt(line[0]);
          arrivalTime = Integer.parseInt(line[1]);
          numPages = Integer.parseInt(line[2]);
          inkType = line[3];

          job = new PrintJob(id, arrivalTime, numPages, inkType);
          System.out.println("\n" + job);
          writeToFile(out, br);
        }
      }

      catch(IOException e)
      {
        System.out.println("\nFile input error!\n");
        e.printStackTrace();
      }

      finally  // Ensure the closing of resources.
      {
        if (br != null)
        {
          try 
          { 
            br.close();
            out.close();
            System.out.println("\nYour transcript file has been written!\n");
          }
          catch(Exception e) { e.printStackTrace(); }
        }
      }
    }

    catch(FileNotFoundException e)
    {
      System.out.println("\nFile not found!\n");
      e.printStackTrace();
    }
    catch(IOException e)
    {
      System.out.println("\nFile output error!\n");
      e.printStackTrace();
    }
  }


  /**
  * Inserts data into the heap and Writes the data to the transcript file.
  */
  private void writeToFile(PrintWriter out, BufferedReader br)
  {
    if (heap.isEmpty() || arrivalTime == 0)  // First print job.
    {
      heap.insert(job);
      System.out.println("\nInserts into queue, job #" + id);
      out.println(timer + " seconds\tjob #" + id + " arrives\t\t\t" + numPages + "/" + inkType);
      out.println(timer + " seconds\tjob #" + id + " starts printing\t\t" + numPages + "/" + inkType);
      return;
    }
    
    else  // Arrival of another job.
    {
      System.out.println("\nPrinting: " + heap.findMin());
      heap.insert(job);
      System.out.println("\nInserts into queue, job #" + id);
      timer += arrivalTime;
      refreshKey();
      out.println(timer + " seconds\tjob #" + id + " arrives\t\t\t" + numPages + "/" + inkType);

      if (arrivalTime > heap.findMin().key) // New job arrives when current job is finished.
      {
        out.print(timer + " seconds\tjob #" + heap.findMin().ID + " finished printing\t");
        out.println(heap.findMin().numPages + "/" + heap.findMin().inkType);
        System.out.println("\nRemoved: job #" + heap.findMin().ID);
        heap.removeMin();

        if (!heap.isEmpty())  // Queue isn't empty, start next job in queue.
        {
          out.print(timer + " seconds\tjob #" + heap.findMin().ID + " starts printing\t\t");
          System.out.println("\nPrinting: " + heap.findMin());
          out.println(heap.findMin().numPages + "/" + heap.findMin().inkType);
        }
      }
    }
    try // Check for end of file.
    {
      if (!br.ready())  // EOF, no more incoming print jobs.
      {
        while (!heap.isEmpty()) // Process every job in queue.
        {
          timer += heap.findMin().key;
          out.print(timer + " seconds\tjob #" + heap.findMin().ID + " finished printing\t");
          out.println(heap.findMin().numPages + "/" + heap.findMin().inkType);
          System.out.println("\nRemoved: job #" + heap.findMin().ID);
          heap.removeMin();
	
          if (!heap.isEmpty())  // Queue isn't empty, start next job in queue.
          {
            out.print(timer + " seconds\tjob #" + heap.findMin().ID + " starts printing\t\t");
            System.out.println("\nPrinting: " + heap.findMin());
            out.println(heap.findMin().numPages + "/" + heap.findMin().inkType);
          }
        }
      }
    } catch(IOException e){ System.out.println("\nFile output error!\n"); }
  }


  /**
   * Refreshes the key of the job that is currently printing.
   */
  private void refreshKey()
  {
    heap.findMin().setKey(heap.findMin().key - job.arrivalTime);
    System.out.println("\nRefreshed key of job printing = " + heap.findMin().key);
  }

  public static void main(String[] args) { new Main(); }
}
