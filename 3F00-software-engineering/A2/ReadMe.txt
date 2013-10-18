IDE: Netbeans 6.7.1
OS: Kubuntu Linux
Compile: can compile by shell using 'g++ -pthread main.cpp -o 3dttt'
Run: after compiling with the above instruction, you can run it with './3dttt'

Description:
------------
The AI of this program consists of a Model-based Reflex agent;
It chooses its actions using condition-action rules (like a Simple Reflex agent) and it also keeps track of the current state of the 
environment (using an internal model).

Thus unlike a Simple Reflex agent, it doesn't ignore its percept history (i.e. it doesn't select an action based on only the current percept). It updates its state over time using environment experience/knowledge. But the agent is still a bit basic (can be problematic).


Evironment Types:
-----------------
- Fully Observable (all relevant information in the environment is known)
- Deterministic (partially Stochastic because of the random move as last resort)
- Sequential (situations dependent on each other)
- Static (finite number of states)
- Discrete (environment is fixed during decision making)
- Multi-Agent (competitive agents)


PEAS description of the environment:
------------------------------------
Performance measure: minimizing opponent's score, maximizing own score
Environment: 8 peg board, each with 3 height levels
Actuators: place a bead on a peg; display board, score and turn to user
Sensors: keyboard input (where the opponent played)


Board display:
--------------
I tried several different ways how to display the board.
I stuck with the method I am using now because I thought it
was the easiest to differentiate the pegs (with the letters),
have a good view of their locations (with the spacing and layout),
and easily know whether a bead is white or red (light or dark bead).


Scoring:
--------
Possible to score vertically, horizontally, and diagonally.
Vertically: 8 ways possible (once per peg)
Horizontally: for every 3 pegs in a straight line (thus 6),
	      there are 3 ways (i.e. 3 height levels),
	      thus 6 * 3 = 18 ways
Diagonally: for every 3 pegs in a straight line (thus 6),
	    there are 2 ways (a digonal in each direction),
	    thus 6 * 2 = 12 ways

Thus in total, 8 + 12 + 18 = 38 checks are needed.


Board representation:
---------------------
I went through different ideas of how to represent the game
in the program. Here are the options I had:
(char array used in these examples)

1) every peg, the bead level, and bead colour:
  eg -> A[3],B[3],...,H[3]

 if the 1st bead on peg A is red, then A[0] = R
 if the 2nd bead on peg A is white, then A[1] = W
 etc..

pros: pegs are easily identifiable
cons: many arrays are needed (8 in total)

2) represent every peg and height level in one array 
  2D array: the peg, the height level, the bead colour
  eg -> board[8][3]

  thus, board[0][3] = W, means
  peg A has at height level 3, a white bead

pros: a single array is needed
cons: 2D arrays are a bit harder to work with than 1D arrays

3) represent different colour beads in different arrays
   eg -> beads_white[12]
	 beads_red[12]

  beads_red[0] = A
  means that the first red bead is on peg A

pros: easy separation of bead colours
cons: not obvious what height level a bead is on

** I went with option 2, because I think that working with one array
(even though it is 2D) is a lot nicer and cleaner.


TO-DO:
------
1. improve the random function (modules decreases randomness)
2. improve AI to use minimax strategy (i.e. turn the agent into a Utility-based agent -- thus the future states are taken into account, and elements of search & planning and optimization are introduced)
3. optimize parallelization (possible to do with minimax -- AI "thinks" while human player is making a move)