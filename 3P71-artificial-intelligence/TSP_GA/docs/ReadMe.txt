Environment: Linux (Kubuntu)
IDE: Netbeans 6.7.1
Compiler used: g++
--

To Compile:
  Can type in the full command -> "g++ -O3 main.cpp -o tsp"
  OR
  Can use the provided shell script -> "sh ./compile.sh"
--

Run executable:
  This program accepts user parameters in the main.
  The order goes: 1) Population Size
		  2) Max Generations
		  3) Crossover Rate
		  4) Mutation Rate
		  5) Number of Elites
		  6) K value for Tournament Selection

  Thus, if for example, you want:
	popSize = 150
	maxGen = 100
	crossRate = 0.9
	mutRate = 0.2
	numElite = 1
	k = 3
  then, you would run the program as "./tsp 150 100 0.9 0.2 1 3" (does not include file input yet)

  For reading in the file, you just pipe in the input (file has to be in local folder).
  You can do this two ways:	1) cat file.txt | ./tsp 150 100 0.9 0.2 1
				2) ./tsp 150 100 0.9 0.2 1 3 < file.txt	(Preferred)

For convenience, there is a shell script provided to run the executable 
-> "sh ./run.sh"

If you want to send the output to a file so that you can view it easier or save for later (Recommended)
-> "sh ./run.sh > output.txt"

--

Miscellaneous:

By default, the program is set to use PMX as its crossover.
To change it to CX, just comment the line that calls PMX and uncomment the line that calls CX.

============
DESIGN NOTES (optional reading)
============

Q: How to represent the GA (in terms of chromosomes)?
A: A living organism consists of cells. In each cell lies the same set of chromosomes.
   Chromosomes are strings of DNA. (http://www.ams.org/featurecolumn/images/chromosome.gif)
   A chromosome consists of genes (i.e. blocks of DNA). Each gene encodes a particular protein.
   Basically, each gene encodes a trait (e.g. colour of hair). Possible settings for a trait
   (e.g. black, brown) are called alleles. Each gene has its own position in the chromosome.
   This position is called locus.

   The complete set of genetic material (i.e. all chromosomes) is called genome.
   A particular set of genes in the genome is called genotype. The organism's characteristics
   is called phenotype.

   In this GA, the following are represented as,

   Chromosome = a single solution to the TSP (i.e. a path of cities, each city visited once)
	-> represented as a list of cities and its total distance
	   (which is the fitness of the solution)

   Gene = a city
	-> represented as a number (integer, float, or double)

   Allele = a city's coordinates
	-> its x-y coordinates stored in a separate 2D list (used like a map container)

   Locus = the specific location of a gene (or DNA sequence) on a chromosome
	-> represented as the index in the list of cities

   Genotype = a population (of chromosomes)
	-> represented as a list containing lists of cities

   Phenotype = the parameter set
	-> population size, generations, crossover rate, mutation rate, elitism rate

Q: How to generate the initial population?
A: Generate a random population of i chromosomes of size j
   (i is the population size specified by the user, j is the amount of cities in the input data)
   Thus the initial population consists of n amount of random, but valid, solutions.
   Each chromosome should also have its fitness calculated and associated with it.

Q: How to evaluate the fitness of a chromosome (or solution)?
A: The fitness evaluation function is the total distance traveled in that path.
   Distance between cities is measured by Euclidean distance. TSP looks for the
   shortest path, thus the chromosome with the lowest total distance, is the most fit.

Q: How to do reproduction of parents (i.e. selection, crossover, mutation, elitism)?
A: You must select two parents for reproduction. Each parent is selected and reproduced
   in a single generation (which means the second parent has to wait until the next generation).
   
   The selection process used here is based on Tournament Selection.
   Select k chromosomes randomly, and from those k, choose the fittest chromosome. (2 <= k <= 4)
   Unfit chromosomes are left in the population in hope of them becoming useful later on.
   (The fitter the chromosome, the more times it is likely to be selected to reproduce.)

   Now that the parents are selected, the reproduction process comes next.
   Reproduction consists of inheritance, crossovers, mutations and elitism.

   Crossovers include inheritance. Some genes are inherited from the parents and 
   some are crossed. The amount of genes that are inherited is determined randomly.
   The crossover rate determines how often crossover will be performed (percentage wise).
   If the crossover rate is 0%, then the offspring is fully inherited (i.e. exact copies
   of parents); if the crossover rate is 100%, then all offspring is made by crossover.
   Crossover is performed (optionally) in hope that new chromosomes will have good parts
   of old chromosomes and maybe the new chromosomes will be better.
   The crossover operator used here is the Partially Mapped Crossover (PMX).
   Cycle Crossover (CX) is provided as a secondary crossover.

   Mutations are made to prevent the GA from getting stuck in local optimas. It is
   performed on the offspring. The mutation rate determines how often parts of the
   chromosome will be mutated. Unfit chromosomes that were left in the population
   earlier because might become useful after mutation.
   The mutation operator used here is the Reciprocal Exchange operator.
   
   Elitism is introduced to prevent the loss of the fittest chromosome during reproduction.
   The n fittest chromosomes are copied into the new population once every generation.
   This guarantees that the best solution won't be lost and improves the GA performance.
   Optionally, only replace the parent with the child if the child is better (in fitness).
   
--
References:
1) Ombuki's lectures & Allen's tutorial
2) http://www.obitko.com/tutorials/genetic-algorithms/index.php
3) http://en.wikipedia.org/wiki/Locus_(genetics)
4) http://chaos.phy.ohiou.edu/~thomas/complex/ga.html