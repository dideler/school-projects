/**
 * Print Job class.
 * A print job contains the id, arrival time, number of pages, inktype,
 * and a key (which is the printing duration of the job and also what the heap
 * is ordered by).
 *
 * Prints 8 pages per minute in black (or 7.5 sec per page).
 * Prints 4 pages per minute in colour (or 15 sec per page).
 *
 * @author  Dennis Ideler
 * @date    December 2008
 */

package printQueue;

class PrintJob
{
  final int ID;
  final int arrivalTime;
  final int numPages;
  final String inkType;
  double key;  // Printing duration is the priority queue's key.


  /**
   * The constructor simply initializes the variables.
   */
  public PrintJob(int ID, int arrivalTime, int numPages, String inkType)
  {
    this.ID = ID;
    this.arrivalTime = arrivalTime;
    this.numPages = numPages;
    this.inkType = inkType;

    if (inkType.equalsIgnoreCase("black"))
      key = numPages * 7.5;
    else
      key = numPages * 15.0;
  }


  /**
   * Sets a new key for the current print job.
   */
  public void setKey(double key)
  {
    this.key = key;
  }


  /**
   * Compares two print jobs.
   * @return -1 if less, 1 if greater, 0 if equal.
   */
  public int compareTo(PrintJob p)
  {
    if (key < p.key) return -1;
    if (key > p.key) return 1;
    return 0;
  }


  /**
   * Converts the contents of a print job to a string. Useful for bug checking.
   * @return Contents of the printjob as a string.
   */
  public String toString()
  {
    return "Job #" + ID + ", arrival time: " + arrivalTime + "s, # pages: "
           + numPages + ", ink type: " + inkType + ", key: " + key;
  }

}
