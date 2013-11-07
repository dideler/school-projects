/* 
 * File:   main.cpp
 * Author: Dennis Ideler (4134466)
 *
 * Created on October 14, 2009, 11:51 PM
 * Finished on October 16, 2009, 4:03 AM
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

int n;				// number of queens that will be in the solution
long steps;			// number of steps to find a solution -- type long to prevent overflows (may be slower than int)
int solutions = 0;	// number of solutions for n queens
bool display;		// if true, display board configuration for solutions
bool singleSolution; // if true, look for a single solution
clock_t start;		// starting time for search


/* The goal test -- returns true if goal has been reached, otherwise false */
bool goalTest(int queensOnBoard)
{ return queensOnBoard == n; }


/* Checks if a location is safe, i.e. not attacked by any Queens */
bool isValid(int queens[], int targetCol, int targetRow)
{
    /* don't need to check if row is safe; row is automatically safe because
     * once a queen is placed, the target row is the next (empty) row */
    for(int row = 0; row < targetRow; row++)
    {
     if( queens[row] == targetCol // column not safe
     || (abs(queens[row] - targetCol) == abs(row - targetRow)) ) // diagonals not safe
            return 0; // conflict found, not a valid location
    }

    return 1; // no conflict found, valid location
}


/* Prints the current board configuration */
void printboard(int queens[])
{
	++solutions;
	
	if(display)
	{
		cout << endl << "Solution " << (solutions) << ": (" << steps << " steps)" << endl;

        for(int i = 0; i < n; i++)
        {
          for(int j = 0; j < n; j++)
          {
            // if column from queen at row i == the column that's about to print
            queens[i] == j ? cout << "Q " : cout << ". ";
          }
          cout << endl; // every column in row printed (i.e. one full row)
        }               // skip line to print new row
        cout << endl;
	}
	steps = 0; // reset counter
}


/* Uninformed search has no information about the problem other than its description.
 * It can only distinguish a goal state from a nongoal state. Thus it systematically
 * generates new states and tests them against the goal.
 *
 * Search space has been greatly reduced. Only checks the next empty row as a
 * target row (thus eliminating all horizontal attacks), and then checks the
 * columns on that row for a safe square. If a safe square has been found, only
 * then is the Queen placed, else backtracks.
 * 
 * queens = array with locations of placed queens
 * row = target row (has equal value to Qs on board, thus multi-purpose) */
void blindsearch(int queens[], int row)
{
    // base case: check if current state is the goal state
    if(goalTest(row))
     	printboard(queens); // if solution found, print board configuration (if enabled)
    
    // base case: check if single solution is required and have at least a solution already
    if(singleSolution && solutions > 0)
		return;
    
    else // solution not yet found
    {
        /* for every queen placed on board (i.e. in the array),
         * check if conflict exists with target position */
        for(int col = 0; col < n; col++)
        {
            steps++;

            /* row is the target row, thus it will be the topmost empty row.
             *e.g.) queensPlaced = 1, then row 0 would be non-empty, because the
             *     first Q would be placed there, target row would then be row 1
             */
            queens[row] = col; // try different column locations for current row

            if(isValid(queens, col, row)) // if location is valid,
            {               // recursively search for a safe spot for next queen
                blindsearch(queens, row+1);
            }
        }
    }    
} // blindsearch


/* Informed search uses problem-specific knowledge, and thus can find solutions
 * more efficiently than uninformed search. 
 * 
 * The heuristic used here is from Wikipedia (see the README for more details).
 * There is only 1 goal possible with heuristics. This heuristic goes for the 
 * "diagonal" solution: it knows that every board has a "diagonal" solution,
 * and thus it places the Queens in these diagonal locations where it is known to be safe.
 * It goes through a number of fitness functions, determining the healthiness and
 * adjusting positions of the Queens, eventually reaching a goal.
 *
 * Works for n == 1 and n >= 4 															*/
void heuristicsearch(int queens[], int remainder)
{
	/** check if it works with n=1 */	
	
	int col;
	// step 1: write even numbers from 2 to n (in order)
	for(int i = 2, col = 0; i <= n; ++col, i=i+2)
		queens[col] = i;
	
	// step 2: move value 2 to the end of the list
	if(remainder == 3 || remainder == 9) // don't need to keep track of 2, because we know it exists
	{
		for(int i = 0;; i++)
		{
			if(queens[i+1] != 0)
				queens[i] = queens[i+1]; // if not at end of list, "pull down" next value
				
			else // next index has value 0, which represents no entry (thus the end)
			{
				queens[i] = 2; // put 2 in the end
				break;
			}
		}
	}
	
	// step 3: append the odd numbers from 1 to n in order (e.g. ...1,3,5,7,..) if remainder is not 8
	if(remainder != 8) // thus append starting at index n/2 (integer division), because current list ends at (n/2)-1
		for(int i = 1, col = n/2; i <= n; ++col, i=i+2)
			queens[col] = i;
			
	else	// remainder is 8, thus append the odds (1 to n), but switch pairs (e.g. ...3,1,7,5,...)
	{
		int j; // j is used to check what value to change i to for the next step (3,1,7,5,11.. => -2,+6,-2,+6,.. etc)
		for(int i = 3, col = n/2, j = 0; i <= n; ++col, ++j)
		{
			queens[col] = i;
			(j&1) ? i=i+6 : i=i-2; // if j is odd, add 6 to i (eg 1->7), else j is even, subtract 2 from i (eg 3->1)
		}
	}
	
	// step 4: if remainder is 2, switch the places of 1 and 3, then move 5 to the end of the list
	if(remainder == 2)
	{ // remainder != 8, thus odds are in order. 1 is first odd placed, thus at index n/2, and 3 at index (n/2)+1
		queens[n/2] = 3;
		queens[(n/2)+1] = 1;	// can hardcode the swap since we previously knew the locations
		
		// we know index of 5 in the list is (n/2)+3, thus we start "pushing down" numbers from the next index, (n/2)+4
		for(int i = (n/2)+2;; ++i)
		{
			if(i < n-1) // if not at end of list (last item in list is at index n-1)
				queens[i] = queens[i+1];
				
			else // i == n-1, thus at end of list, place 5
			{
				queens[i] = 5;
				break;
			}
		}
	}
	
	// step 5: if remainder is 3 or 9, move 1 and 3 to the end of the list
	if(remainder == 3 || remainder == 9)
	{
		for(int i = n/2;; ++i) // start at index of 1
		{
			if(i < n-2) // if not at the position before the last (since last 2 positions are for 1 and 3)
				queens[i] = queens[i+2];
			
			else // at position n-2, can now place 1 and then 3
			{
				queens[i] = 1;
				queens[i+1] = 3;
				break;
			}
		}
	}
	
	// step 6: done, print board configuration
	// place first-column queen in row with first number in list,
	// place second-column queen in row with second number in list, etc.
	// --> thus list index = column, and value at list index = row
	// NOTE: because array starts at 0, columns start at 0, but list values start at 1, thus rows start at 1
	
	double end = clock();	// end time
    cout << "Time elapsed: " << (end - start) / CLOCKS_PER_SEC << " Sec(s) (approximately)\n";
	cout << "Solution found. Would you like to print Queens positions? [y/n]" << endl;
	bool displayPos = false;
	char option;
	cin >> option;
   	switch (option)
   	{
   	    case 'y':
   	    case 'Y':
   	    	displayPos = true;
        	break;
        case 'n':
        case 'N':
            break;
      	default:
            cout << "Assuming you chose 'n', continuing shortly..." << endl;
            sleep(1);
    }
	
	if(display) // only print board if option enabled
	{
		cout << endl;
		for(int row = 1; row <= n; row++)
	    {
	    	for(int col = 0; col < n; col++)
	        {
	        	// if row from queen at current column == the row that's about to print
	            queens[col] == row ? cout << "Q " : cout << ". ";
	        }
	        cout << endl;
	    }
    }
    
    if(displayPos) // only print positions if option enabled
    {
	    cout << "\nPositions of Queens:" << endl;
	    for(int row = 1; row <= n; row++)
	    	for(int col = 0; col < n; col++)
		        if(queens[col] == row) cout << "row = " << row << " \tcol = " << col+1 << endl;
		        // col+1 when printing because represented in array starting at 0

		cout << endl;
	}
}


/*
 * N-Queens: A queen is a chess piece that can move over all squares of a
 * chessboard that are horizontal, vertical, or diagonal to it.
 *
 * The problem is to place the N queens on an NxN chessboard, such that no queen
 * takes any other queen (This means that at most a single queen in each row,
 * in each column and all diagonals and exactly N Queens on the chess board).
 * Only 1 queen can be placed on each board square.
 *
 * 1. Use a blind search algorithm from chapter 3 (Class textbook).
 * 2. Use a heuristic search from chapter 4. Note that heuristic searches are reliant on pseudo-random number generators. If you change the seed of the RAND generator, you will get a different search. Hence you should run heuristic searches a number of times with new seeds. An example of a scheme you can use here is as follows. The initial board is one in which the queens are randomly placed all over the board. The next-state generator will take a current board, and generate one or more new boards by taking one of the queens, and moving it to a different location. Each new board needs to have a heuristic score assigned to it. One straight-forward heuristic is to count the number of queens that are threatening to attack each other on a given configuration. Hence, some new boards will be “fitter” than others, in that there may be fewer queens threatening to attack one another.
 * -----------------------------------------------------------------------------
 * In this problem, we assume that the board goes from 0 to n-1, rather than
 * 1 to n (easier to represent it this way because of arrays)
 */
int main(int argc, char** argv)
{
    cout << endl << "Input size of n: ";
    cin >> n;

    if(n < 1)
    {
		cout << endl << "Please enter a positive integer." << endl;
		exit(0);
    }
    cout << n << "x" << n << " board, " << n << " queens" << endl << endl;

    /* not representing the full board, thus don't need an array that contains n*n locations
     * instead, going to have an array with the locations of safely placed queens
     * i.e. my blind search has the format board[row] = column
     		(thus there would be a Queen at that specific row and column)
     		my heuristic search has the format board[column] = row */
    int board[n];
    for(int i = 0; i < n; i++) // initialize to 0
        board[i] = 0;
    
    //cout << "array size = " << sizeof(board)/sizeof(int) << "indexes" << endl;

    int option1, option2;
    char option3,option4;
    cout << "Press 1 for Blind Search." << endl;
    cout << "Press 2 for Heuristic Search." << endl;
    cin >> option1;
    cout << endl;

    int queensPlaced; // number of queens currently placed on the board

    if(option1 == 1)
    {
		queensPlaced = 0; // initial state is an empty board, thus no queens have been placed yet
		steps = 0;
		
		cout << "Blind Search (uninformed) has been chosen.\n"
		"Would you like to search for the first solution or all solutions?\n"
		"Press 1 for a single solution.\nPress any other key for all solutions." << endl;
		cin >> option2;
		
		if(option2 == 1) // search for a single solution
		{
			singleSolution = true;
			display = true;
		}
		else // search for all solutions
		{
			singleSolution = false;
			
			cout << "\nWould you like to display the board configuration of every solution?\n"
			"Disabling will improve execution speed. [y/n]" << endl;
			cin >> option3;
        	switch (option3)
        	{
        	    case 'y':
        	    case 'Y':
        	    	display = true;
        	        break;
        	    case 'n':
        	    case 'N':
        	        display = false;
        	        break;
        	    default:
        	        cout << "Assuming you chose 'y', continuing shortly..." << endl;
        	        display = true;
        	        sleep(1);
        	}
        	cout << "\nThe program will search exhaustively and stop when all solutions have been found.\n"
        	"If a minute has passed and the program hasn't finished the search for all solutions, "
        	"you can stop the program with ctrl+c.\nWould you like to continue? [y/n]" << endl;
        	cin >> option4;
        	switch (option4)
        	{
        	    case 'y':
        	    case 'Y':
           	    	break; // do nothing, continue exit execution
            	case 'n':
            	case 'N':
            	    exit(0);
            	    break;
            	default:
            	    cout << "Assuming you chose 'y', continuing shortly..." << endl;
            	    sleep(1);
        	}
        }
        start = clock();					// start time
		blindsearch(board, queensPlaced);	// search
		double end = clock();				// end time
		
        if(solutions == 0) cout << "\nNo solution(s) found for n = " << n << endl;

        if(option2 != 1) // show # of solutions found if you don't print out the boards
	        if(!display) cout << "\nSolutions found: " << solutions << endl;

        cout << "Time elapsed: " << (end - start) / CLOCKS_PER_SEC << " Sec(s) (approximately)\n";
    }
    else if(option1 == 2)
    {
    	int r = n % 12; // step 0: preprocess the remainder (which is used in the heuristic)
    	
    	cout << "Would you like to display the board configuration for the solution?\n"
    	"If disabled, Queen positions will still be printed, but board will not be.\n"
		"(Recommended disabling option when using large values of n) [y/n]" << endl;
		cin >> option3;
        switch (option3)
        {
            case 'y':
            case 'Y':
            	display = true;
                break;
            case 'n':
            case 'N':
                display = false;
                break;
            default:
                cout << "Assuming you chose 'n', continuing shortly..." << endl;
                display = false;
                sleep(1);
        }
		cout << "\nHeuristic Search (informed) has been chosen.\n"
        "The program will only search for a single solution and then terminate.\n"
        "If no solution has been found in under a minute, you can stop the program with ctrl+c.\n"
        "Would you like to continue? [y/n]" << endl;
        cin >> option4;
        cout << endl;
        switch (option4)
        {
            case 'y':
            case 'Y':
            	if(n == 2 || n == 3)
            	{
            		cout << "There are no solutions for n = " << n << ".\n"
            		"Heuristic search only works (in theory) for n = 1 or n >= 4, \n"
            		"because it's not exhaustive (doesn't try all solutions to know "
            		"if a potential solution is in the set of legal solutions), "
            		"it will consider a solution 'legal' if it sees it (and all the "
            		"steps that lead up to it) as healthy/fit." << endl;
            		exit(0);
            	}
            	break;
           	case 'n':
           	case 'N':
           	    exit(0);
           	    break;
           	default:
           	    cout << "Assuming you chose 'y', continuing shortly..." << endl;
           	    sleep(1);
        }
       	start = clock();	// start time
       	heuristicsearch(board, r);	// search
    }
    else cout << "Option not recognized; Terminating program." << endl;

    return (EXIT_SUCCESS);
}

