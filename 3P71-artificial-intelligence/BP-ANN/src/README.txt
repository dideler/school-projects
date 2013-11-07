Implemented & tested on Kubuntu (Linux).

To compile from terminal: g++ main.cpp -o ANN -O3
or use the provided script: sh ./compile.sh

To run from terminal: ./ANN < Patterns.dat
or use the provided script: sh ./run.sh

--------------

Notes:

- I used loops whenever doing processes on the output layer.
  Because it's just a single output node, no loop is needed,
  I provided it in case I ever add more than one output node.

- I wrote a lot of documentation, hopefully I get to finish it.