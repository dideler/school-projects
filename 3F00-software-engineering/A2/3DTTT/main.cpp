/* 
 * File:   main.cpp
 * Author: Dennis Ideler <di07ty@brocku.ca> [4134466]
 * Version: 1.1
 *  v1.1 log: - added system time as random number seed (increased randomness)
 *
 * Created on October 18, 2009, 5:58 PM
 * Last modified on November 4, 2009, 1:47 AM
 * -------------------------------------
 * http://www.cosc.brocku.ca/~vwojcik/3F00/a2.html
 *
 * Upon launching the game, the main program would ask the user who is to go
 * first. Having gotten this answer, the main program should launch a suitable
 * game playing thread / task.
 *
 * The main program should be responsible for:
 *
 *  * The dialogue with the human player;
 *  * The dialogue with the game playing task / thread;
 *  * Displaying simple (ASCII) game interface, showing the state of the game;
 *  * Tallying the alignments for both players as game progresses;
 *  * Announcing the winner;
 *  * Terminating the game when needed.
 *
 * The game playing thread / task should be responsible for:
 *
 *  * Accepting the moves of a human player
 *    (communicated to it by the main program);
 *  * Informing the main program about its moves;
 *  * Playing the 3D TTT game to the best of its ability;
 *  * Being as responsive as possible: "thinking" about its likely next move
 *    while attentively waiting for the next human move.
 */

#include <cstdlib>
#include <pthread.h>
#include <iostream>
using namespace std;

#define EMPTY   0 // define the states of a position on a peg
#define RED     1
#define WHITE   2
#define A       0 // define peg values
#define B       1
#define C       2
#define D       3
#define E       4
#define F       5
#define G       6
#define H       7

int redScore, whiteScore; // globals for keeping track of the score
int board[8][3]; // the board state
int cmpCol, hmnCol; // computer and human bead colour


/* Prints the board -- prints each "row" of pegs separately */
void printBoard()
{
    // the board and beads are drawn top down (so height 3 first)

    cout << "A     B     C" << endl;
    for(int j=2; j >= 0; j--)
    {    for(int i = A; i <= C; i++) // top 3 pegs (A, B, C)
        {
            if(board[i][j] == RED)
                cout << "*";
            else if(board[i][j] == WHITE)
                cout << "o";
            else // no bead
                cout << "|";
            cout << "     "; // the space between the pegs
            if(i == 2) // last peg, go to new line
                cout << endl;
        }
    }
    cout << "   D     E" << endl;
    for(int j=2; j >= 0; j--)
    {    for(int i = D; i <= E; i++) // middle 2 pegs (D, E)
        {
        if( i == 3)
            cout << "   "; // the space between the pegs
        else
            cout << "     ";

            if(board[i][j] == RED)
                cout << "*";
            else if(board[i][j] == WHITE)
                cout << "o";
            else // no bead
                cout << "|";
            if(i == 4) // last peg, go to new line
                cout << endl;
        }
    }
    cout << "F     G     H" << endl;
    for(int j=2; j >= 0; j--)
    {    for(int i = F; i <= H; i++) // bottom 3 pegs (F, G, H)
        {
            if(board[i][j] == RED)
                cout << "*";
            else if(board[i][j] == WHITE)
                cout << "o";
            else // no bead
                cout << "|";
            cout << "     "; // the space between the pegs
            if(i == 7) // last peg, go to new line
                cout << endl;
        }
    }
    cout << endl;
} // printBoard


/* Computes the horizontal scores (called by horizontalChecks()).
 * Checks the 3 passed in pegs for a valid horizontal score. */
void horizontalScore(int peg1, int peg2, int peg3)
{
    for(int i = 0; i < 3; i++)
    {
        if(board[peg1][i] == RED && board[peg2][i] == RED &&
           board[peg3][i] == RED) redScore++;
        else if(board[peg1][i] == WHITE && board[peg2][i] == WHITE &&
                board[peg3][i] == WHITE) whiteScore++;
    }
}


/* Computes the diagonal scores (called by diagonalChecks()).
 * Checks the 3 passed in pegs for a valid diagonal score. */
void diagonalScore(int peg1, int peg2, int peg3)
{
    // check diagonal 1
    if(board[peg1][0] == RED && board[peg2][1] == RED && board[peg3][2] == RED)
        redScore++;
    else if(board[peg1][0] == WHITE && board[peg2][1] == WHITE && board[peg3][2] == WHITE)
        whiteScore++;

    // check diagonal 2
    if(board[peg1][2] == RED && board[peg2][1] == RED && board[peg3][0] == RED)
        redScore++;
    else if(board[peg1][2] == WHITE && board[peg2][1] == WHITE && board[peg3][0] == WHITE)
        whiteScore++;
}


/* Checks for vertical wins -- 1 check per peg, thus 8 checks.
 * Method was small enough not to need a verticalScore method. */
void verticalChecks()
{
    for(int i = A; i <= H; i++)
    {
        if(board[i][0] == RED && board[i][1] == RED && board[i][2] == RED)
            redScore++;
        else if(board[i][0] == WHITE && board[i][1] == WHITE &&
                board[i][2] == WHITE) whiteScore++;
    }
}


/* Checks for horizontal wins -- check all 6 combinations of 3 consecutive pegs,
 * at each height level i (i = 0,1,2), thus 6 * 3 = 18 checks */
void horizontalChecks()
{
    horizontalScore(A, B, C); // combination 1
    horizontalScore(F, G, H); // -"       "- 2
    horizontalScore(A, D, G); // -"       "- 3
    horizontalScore(B, E, H); // -"       "- 4
    horizontalScore(B, D, F); // -"       "- 5
    horizontalScore(C, E, G); // -"       "- 6
} // horizontalChecks


/* Checks for diagonal wins -- similar to horizontal checks, but instead of being
 * able to score 3 ways on 3 different height levels, you can only score twice
 * (maximum) on 3 different height levels, thus in both diagonal directions.
 * e.g. for peg 1,2,and 3: check height = 2,1,0 and 0,1,2 */
void diagonalChecks()
{
    diagonalScore(A, B, C); // combination 1
    diagonalScore(F, G, H); // -"       "- 2
    diagonalScore(A, D, G); // -"       "- 3
    diagonalScore(B, E, H); // -"       "- 4
    diagonalScore(B, D, F); // -"       "- 5
    diagonalScore(C, E, G); // -"       "- 6
} // diagonalChecks


/* Checks for scoring combinations and tallies up the score for both players */
void computeScore()
{
    verticalChecks();
    horizontalChecks();
    diagonalChecks();
}


/* Returns human's score at the time when called */
int humanScore()
{
    if(hmnCol == RED) return redScore;
    else return whiteScore;
}


/* Returns computer's score at the time when called */
int compScore()
{
    if(cmpCol == WHITE) return whiteScore;
    else return redScore;
}


/* Checks if a move to score/block horizontally is valid, if it is, it will make
 * the move and return true, else returns false.
 * When there are 2 matching beads in a row, the 3rd open spot can be in three
 * different places (any of the 3 pegs), must check all cases.
 * peg1,2,3 = the pegs to check to determine if AI can block/score.
 * colour = the colour you are looking to block/score. */
bool isHorizMoveValid(int peg1, int peg2, int peg3, int colour)
{
    for(int i = 0; i < 3; i++) // check each height level
    {
        if(board[peg1][i] == colour && board[peg2][i] == colour && board[peg3][i] == EMPTY)
        {
            // bead must lay ontop of another unless it is the first bead
            if( (i == 1 && board[peg3][0] != EMPTY) ||
                (i == 2 && board[peg3][1] != EMPTY) || (i == 0) )
            {
                board[peg3][i] = cmpCol;
                cout << "\t\tYour opponent played on peg " << (char)(peg3+'A') << endl;
                return true;
            }
        }
        if(board[peg1][i] == colour && board[peg3][i] == colour && board[peg2][i] == EMPTY)
        {
            if( (i == 1 && board[peg2][0] != EMPTY) ||
                (i == 2 && board[peg2][1] != EMPTY) || (i == 0) )
            {
                board[peg2][i] = cmpCol;
                cout << "\t\tYour opponent played on peg " << (char)(peg2+'A') << endl;
                return true;
            }
        }
        if(board[peg2][i] == colour && board[peg3][i] == colour && board[peg1][i] == EMPTY)
        {
            if( (i == 1 && board[peg1][0] != EMPTY) ||
                (i == 2 && board[peg1][1] != EMPTY) || (i == 0) )
            {
                board[peg1][i] = cmpCol;
                cout << "\t\tYour opponent played on peg " << (char)(peg1+'A') << endl;
                return true;
            }
        }
    }
    return false; // couldn't find a move that will block/score
} // isHorizMoveValid


/* Blocks or scores horizontally
 * colour = the bead colour to check for. Same parameter is used in the diagonal
 * and vertical methods below.
 * If blocking, colour = human colour; if scoring, colour = computer colour. */
bool blockOrScoreHoriz(int colour)
{
    /* for every 3-peg combination, need to check 3 different heights and
     * 3 different peg combinations (e.g. peg 1 & 2, peg 1 & 3, and peg 2 & 3)*/

    if(isHorizMoveValid(A, B, C, colour)) return true; // combination 1
    if(isHorizMoveValid(F, G, H, colour)) return true; // -"       "- 2
    if(isHorizMoveValid(A, D, G, colour)) return true; // -"       "- 3
    if(isHorizMoveValid(B, E, H, colour)) return true; // -"       "- 4
    if(isHorizMoveValid(B, D, F, colour)) return true; // -"       "- 5
    if(isHorizMoveValid(C, E, G, colour)) return true; // -"       "- 6

    return false;
} // blockOrScoreHoriz


/* Checks if a move to score/block horizontally is valid, if it is, it will make
 * the move and return true, else returns false.
 * Similar to isHorizMoveValid(), there are 3 cases to check per diagonal: peg
 * 1 & 2, 1 & 3, and 2 & 3. Then check if the leftover peg is valid for play. */
bool isDiagMoveValid(int peg1, int peg2, int peg3, int colour)
{
    // check each case for diagonal 1 ( / )
    if(board[peg1][0] == colour && board[peg2][1] == colour &&
       board[peg3][2] == EMPTY && board[peg3][1] != EMPTY) // can assume there is a 1st bead
    {
        board[peg3][2] = cmpCol;
        cout << "\t\tYour opponent played on peg " << (char)(peg3+'A') << endl;
        return true;
    }
    if(board[peg1][0] == colour && board[peg3][2] == colour &&
       board[peg2][1] == EMPTY && board[peg2][0] != EMPTY)
    {
        board[peg2][1] = cmpCol;
        cout << "\t\tYour opponent played on peg " << (char)(peg2+'A') << endl;
        return true;
    }
    if(board[peg2][1] == colour && board[peg3][2] == colour &&
       board[peg1][0] == EMPTY) // height 0 is the first peg
    {
        board[peg1][0] = cmpCol;
        cout << "\t\tYour opponent played on peg " << (char)(peg1+'A') << endl;
        return true;
    }
    // check each case for diagonal 2 ( \ )
    if(board[peg1][2] == colour && board[peg2][1] == colour &&
       board[peg3][0] == EMPTY)
    {
        board[peg3][0] = cmpCol;
        cout << "\t\tYour opponent played on peg " << (char)(peg3+'A') << endl;
        return true;
    }
    if(board[peg1][2] == colour && board[peg3][0] == colour &&
       board[peg2][1] == EMPTY && board[peg2][0] != EMPTY)
    {
        board[peg2][1] = cmpCol;
        cout << "\t\tYour opponent played on peg " << (char)(peg2+'A') << endl;
        return true;
    }
    if(board[peg2][1] == colour && board[peg3][0] == colour &&
       board[peg1][2] == EMPTY && board[peg1][1] != EMPTY)
    {
        board[peg1][2] = cmpCol;
        cout << "\t\tYour opponent played on peg " << (char)(peg1+'A') << endl;
        return true;
    }
    return false; // couldn't find a move that will block/score
}


/* Blocks or scores diagonally. */
bool blockOrScoreDiag(int colour)
{
    if(isDiagMoveValid(A, B, C, colour)) return true; // combination 1
    if(isDiagMoveValid(F, G, H, colour)) return true; // -"       "- 2
    if(isDiagMoveValid(A, D, G, colour)) return true; // -"       "- 3
    if(isDiagMoveValid(B, E, H, colour)) return true; // -"       "- 4
    if(isDiagMoveValid(B, D, F, colour)) return true; // -"       "- 5
    if(isDiagMoveValid(C, E, G, colour)) return true; // -"       "- 6

    return false; // couldn't find a move that will block/score
} // blockOrScoreDiag


/* Blocks or scores vertically.
 * Can only block/score on the top height level, thus checks if the first two
 * beads are of equal colour and if the top spot is empty, then places bead */
bool blockOrScoreVert(int colour)
{
    for(int i = A; i <= H; i++)
    {
        if(board[i][0] == colour && board[i][1] == colour && board[i][2] == EMPTY)
        {
            board[i][2] = cmpCol;
            cout << "\t\tYour opponent played on peg " << (char)(i+'A') << endl;
            return true;
        }
    }
    return false; // couldn't find a move that will block/score
} // blockOrScoreVert


/* Blocks the first spotted winning move for the human player. */
bool blockMove()
{
    // horizontally has the most possible ways of scoring (18), so check first
    if(blockOrScoreHoriz(hmnCol)) return true;

    // diagonally has the next most possible ways of scoring (12)
    if(blockOrScoreDiag(hmnCol)) return true;

    // last is vertical, with the least amount of ways to score (8)
    if(blockOrScoreVert(hmnCol)) return true;

    return false;
}


/* Makes a winning move on the first spotted opportunity. */
bool winningMove()
{
    // horizontally has the most possible ways of scoring (18), so check first
    if(blockOrScoreHoriz(cmpCol)) return true;

    // diagonally has the next most possible ways of scoring (12)
    if(blockOrScoreDiag(cmpCol)) return true;

    // last is vertical, with the least amount of ways to score (8)
    if(blockOrScoreVert(cmpCol)) return true;

    return false;
}


/* Places a bead on the specified peg (if valid).
 * Returns true if it can place a bead on the first available height (and will
 * place the bead), else if the peg is full, cannot place bead. */
bool placeBead(int colour, int peg)
{
    for(int height = 0; height < 3; height++)
    {
        if(board[peg][height] == EMPTY)
        {
            if(colour == RED) board[peg][height] = RED;
            else board[peg][height] = WHITE;
            return true;
        }
    }
    return false; // peg is full
}


/* If the AI cannot block a winning move or make a winning move, then it shall
 * make a random move. Making it choose the best move as its last option would
 * make it close to (but still not) a rational agent. It would also make it too
 * hard to beat. */
void randomMove()
{
    bool moveValid = false;
    int peg;
    while(!moveValid)
    {
        peg = rand() % 8;
        moveValid = placeBead(cmpCol, peg); // place on a random peg
    }
    cout << "\t\tYour opponent played on peg " << (char)(peg+'A') << endl;
}


/* The AI -- not too weak, not too strong
 * First try to block a winning move of the human player, if there is none,
 * then try to make a winning move, if there is none, then make any move. */
void computerTurn()
{
    // kept blockMove and winningMove as separate methods for readability
    if(blockMove()) return;
    if(winningMove()) return;
    randomMove();
}


/* Specify what to do for every human turn. */
void humanTurn(int beadNum)
{
    bool moveValid = false;
    char peg;
    printBoard();
    
    while(!moveValid)
    {
        cout << "What peg would you like to play bead #" << beadNum << " on?" << endl;
        cin >> peg;
        cout << endl;
        switch (peg)
        {
            case 'q':
            case 'Q':
                cout << "Thank you for playing!\n" << endl;
                exit(0);
                break;
            case 'a':
            case 'A':
                moveValid = placeBead(hmnCol, A);
                if(!moveValid)
                    cout << "Peg A is full, please try another peg." << endl;
                break;
            case 'b':
            case 'B':
                moveValid = placeBead(hmnCol, B);
                if(!moveValid)
                    cout << "Peg B is full, please try another peg." << endl;
                break;
            case 'c':
            case 'C':
                moveValid = placeBead(hmnCol, C);
                if(!moveValid)
                    cout << "Peg C is full, please try another peg." << endl;
                break;
            case 'd':
            case 'D':
                moveValid = placeBead(hmnCol, D);
                if(!moveValid)
                    cout << "Peg D is full, please try another peg." << endl;
                break;
            case 'e':
            case 'E':
                moveValid = placeBead(hmnCol, E);
                if(!moveValid)
                    cout << "Peg E is full, please try another peg." << endl;
                break;
            case 'f':
            case 'F':
                moveValid = placeBead(hmnCol, F);
                if(!moveValid)
                    cout << "Peg F is full, please try another peg." << endl;
                break;
            case 'g':
            case 'G':
                moveValid = placeBead(hmnCol, G);
                if(!moveValid)
                    cout << "Peg G is full, please try another peg." << endl;
                break;
            case 'h':
            case 'H':
                moveValid = placeBead(hmnCol, H);
                if(!moveValid)
                    cout << "Peg H is full, please try another peg." << endl;
                break;
            default:
                cout << "Input not understood, please try again." << endl;
        } // switch case
    } // while loop
}


/* The game playing function, calls each player's turn accordingly. */
void * play(void * dummyPtr)
{
    int beadNum = 1; // indicates what bead number the player is placing

    for(int i = 1; i <= 12; i++, beadNum++) // 12 beads played each before a game is over
    {
        if(hmnCol == RED) // player and computer must play in the correct order
        {
            humanTurn(beadNum);
            computerTurn();
        }
        else
        {
            computerTurn();
            humanTurn(beadNum);
        }
    }
}


/* Prints out starting messages and initializes values */
void start()
{
    // clear board
    for(int i = A; i <= H; ++i)
        for(int j=0; j < 3; ++j)
            board[i][j] = 0;

    cout << "Welcome to 3D Tic Tac Toe!\n\n[Empty Board]" << endl;
    printBoard();
    cout << "There are 8 pegs in total, labeled A through H.\n"
            "You can score by having 3 beads placed in a row either vertically,"
            " horizontally, or diagonally.\nAt the end of the game, the winner"
            " is determined by the player with the highest score.\n"
            "The end is reached after each player has played 12 beads.\n"
            "The board state is printed out before every human turn.\n"
            "If you'd like to quit, you can do so at your turn by pressing the"
            " 'Q' key.\nIf you'd like to end the program at any time, you can "
            "do so with ctrl+c.\n\nWhat colour would you like to play as?\n"
            "Press R for Red, and W for White. (Red has first move)" << endl;
    char option1;
    cin >> option1;
    switch (option1)
    {
        case 'r':
        case 'R':
            // player chooses Red
            hmnCol = RED;
            cmpCol = WHITE;
            cout << "You will be playing as Red (indicated by *).\n" << endl;
            break;
        case 'w':
        case 'W':
            // player chooses White
            hmnCol = WHITE;
            cmpCol = RED;
            cout << "You will be playing as White (indicated by o).\n" << endl;
            break;
        default:
            // players is assigned Red
            hmnCol = RED;
            cmpCol = WHITE;
            cout << "Input not understood, assigning you to play as Red "
                    "(indicated by *).\n" << endl;
    }
} //start


/* Ends the game (if the user chooses not to retry) */
bool end()
{
  cout << "[Game Over]" << endl;
  printBoard();
  computeScore();
  cout << "Human: " << humanScore() << ", Comp: " << compScore() << endl;
  if(humanScore() > compScore()) cout << "You won, congratulations!" << endl;
  else if(humanScore() == compScore()) cout << "Tie game!" << endl;
  else cout << "Unfortunately, you lost." << endl;
  cout << "Would you like to try again? [y/n]" << endl;
  char option2;
  cin >> option2;
  switch (option2)
  {
    case 'y':
    case 'Y':
        cout << endl;
        return true;
        break;
    case 'n':
    case 'N':
        break;
    default:
        cout << "Input not understood, ending game." << endl;
  }
  cout << "\nThank you for playing!\n" << endl;
  return false;
} // end


/*Notes:
 *
 * Simplicity was kept in mind when designing this program, because advanced
 * methods, data structures, etc., are not necessarily the best way to get a
 * program working for a simple job.
 * 
 * Also, I used C++ but no object-oriented programming. OOP is useful for
 * building large, reusable programs, however, this program is designed to
 * be small (in terms of complexity). The basic assumption of OOP doesn't apply
 * in this assignment, thus defining complicated new objects (as opposed to 
 * using predefined objects) is likely to be a waste of time. The trick to
 * successful programming is not abandoning style, but using one approriate  to
 * the scale of the job.
 * 
 * Global variables tend to be thought of as bad practice; however passing
 * (the same) variables to many functions can produce a lot of unnessecary side
 * effects. At first I passed many variables but it became messy, and I decided
 * to use some globals.
 *
 * The amount of alignments (i.e. scores) are tallied at the end of the game
 * (as described in the problem description) rather than during the game,
 * this makes more sense to me.
 */
int main(int argc, char** argv)
{
    srand ( time(NULL) ); // initialize random seed (otherwise not truly random)
    pthread_t gamePlaying;
    bool retry = false;
    do
    {
        start();
        pthread_create(&gamePlaying, NULL, play, NULL); // create thread
        pthread_join(gamePlaying, NULL); // wait on thread to finish
        retry = end();
    } while(retry);
    
    return (EXIT_SUCCESS);
}

