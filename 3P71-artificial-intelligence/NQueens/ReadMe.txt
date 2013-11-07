IDE: (actually just used a text editor) gedit
OS: CentOS (in J310 and D205)
Compiler: g++

Compiling:
Compile locally from a lab computer (Sandcastle is slower, throttles users' processes)
If you are compiling by terminal (such as bash):
	compile for testing/debugging: g++ -g main.cpp -o nqueens
	compile for production: g++ -O3 main.cpp -o nqueens
	(used -O2 at first but -O3 is a lot better)

Run executable: ./nqueens
-----------------------------------------------------------------
Notes:

- For blind search, if you are testing a large n (e.g. n >= 8)
  and displaying the board configurations of the solutions,
  then it is recommended that you pipe the output to a text file.
    e.g. ./nqueens > output.txt

- Blind Search: 
	find all solutions for n in under a minute => max n = 14 (with board display disabled I believe)
	find a solution in under a minute => max n = 31

- Heuristic Search:
	find a solution for n in under a minute => max n ~ in the millions (~10 million and up produced segfaults)
---------------------------------------------------------------------------------------
Heuristic used from Wikipedia: (http://en.wikipedia.org/wiki/Eight_queens_puzzle#Constructing_a_solution)
This heuristic solves n queens for any n n ≥ 4 or n = 1:

   1. Divide n by 12. Remember the remainder (n is 8 for the eight queens puzzle).
   2. Write a list of the even numbers from 2 to n in order.
   3. If the remainder is 3 or 9, move 2 to the end of the list.
   4. Append the odd numbers from 1 to n in order, but, if the remainder is 8, switch pairs (i.e. 3, 1, 7, 5, 11, 9, …).
   5. If the remainder is 2, switch the places of 1 and 3, then move 5 to the end of the list.
   6. If the remainder is 3 or 9, move 1 and 3 to the end of the list.
   7. Place the first-column queen in the row with the first number in the list, place the second-column queen in the row 		  with the second number in the list, etc.

For n = 8 this results in the solution shown above. A few more examples follow.

    * 14 queens (remainder 2): 2, 4, 6, 8, 10, 12, 14, 3, 1, 7, 9, 11, 13, 5.
    * 15 queens (remainder 3): 4, 6, 8, 10, 12, 14, 2, 5, 7, 9, 11, 13, 15, 1, 3.
    * 20 queens (remainder 8): 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 3, 1, 7, 5, 11, 9, 15, 13, 19, 17.
-----------------------------------------------------------------------------------------------------
