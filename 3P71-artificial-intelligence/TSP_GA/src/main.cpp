/* 
 * File:   main.cpp
 * Author: Dennis Ideler <di07ty@brocku.ca> [4134466]
 *
 * Created on November 1, 2009, 2:47 PM -- Finished on November 7, 2009
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>   // EOF and sscanf
#include <cmath>    // sqrt
#include <algorithm>// random_shuffle
#include <ctime>    // time used as seed for random number generator
#include <limits>   // max double
#include <map>
using namespace std;

#define X 0
#define Y 1
#define EMPTY 0

struct USERINPUT // GA parameters
{
    float crossRate;  // crossover rate or crossover probability
    float mutRate;    // mutation rate or mutation probability
    int popSize;      // population size (amount of chromosomes in a generation)
    int maxGen;       // maximum generation span
    int numElite;     // number of elites
    int k;            // k chromosomes selected during Tournament Selection
} GA;

struct GENOTYPE // the genotype is the population of chromosomes
{
    double ** pop; // population -- double for extra precision in fitness
    double ** newPop; // new population
    double * elite; // elite chromosome
} genotype;

// prototypes
void initialPopulation(int cities, int map[][2]);
double evaluateFitness(int cities, int chromosome[], int map[][2]);
void geneticAlgorithm(int cities, int map[][2]);
void findElite(int cities, double prevBest);
int tournamentSelection(void);
void pmCrossover(int cities, int parent1, int parent2, int start);
void cCrossover(int cities, int parent1, int parent2, int start);
void reMutation(int cities, int run);


/* Prints the current population to standard output. */
void printPopulation(int cities)
{
    for(int i = 0; i < GA.popSize; ++i)
    {
        cout << "chromosome: " << i << "\tfitness = " << genotype.pop[i][0] << endl;

        for(int j = 1; j <= cities; ++j)
        {
            cout << "gene " << j << " = city " << genotype.pop[i][j] << endl;
        }
        cout << endl;
    }
} // printPopulation


/* Create a static dictionary (or "map") with input data.
 * The map will be queried to retrieve a specific city's x-y coordinates. */
void readData()
{
    string str;
    int node, x, y, cities;

    // read in junk data
    while(cin >> str)
    {
        if( str.compare("DIMENSION") == 0 )
	{
		cin >> str; // read in the colon
		cin >> cities; // read in amount of nodes/cities
	}
	if( str.compare("NODE_COORD_SECTION") == 0 ) break; // real data follows
    }

    int map[cities+1][2]; // 2nd dimension stores the x-y coords
    map[0][X] = 0; map[0][Y] = 0; // index 0 is not used, clear it to be safe

    // read in important data
    while(cin >> node && !cin.eof())
    {
	cin >> x;
	cin >> y;
        map[node][X] = x;
        map[node][Y] = y;
	//cout << "[node] " << node << "\t[x] " << map[node][X] << "\t[y] " << map[node][Y] << endl;
    }

    initialPopulation(cities, map);
} // readData


/* Creates a population of popSize and generates random legal chromosomes.
 *
 * Algorithm is started with a set of solutions (represented by chromosomes)
 * called population. These chromosomes are randomly generated.
 *
 * Population represented as: population[chromosome][gene] */
void initialPopulation(int cities, int map[][2])
{
    // allocation of multidimensional dynamic memory array
    genotype.pop = new double *[GA.popSize];
    for(int i = 0; i < GA.popSize; i++)
	genotype.pop[i] = new double[cities+1];

    // initialize/clear 2D-array
    for(int i = 0; i < GA.popSize; ++i)
        for(int j = 0; j < cities+1; ++j)
            genotype.pop[i][j] = 0.0;

    // do the same for the elite
    genotype.elite = new double[cities+1];
    for(int i = 0; i <= cities; ++i)
        genotype.elite[i] = 0.0;

    int shuffle[cities+1]; // temp array to perform shuffle of genes on

    for(int i = 1; i <= cities; ++i) // fill chromosome with a simple solution
        shuffle[i] = i;

    // randomly generate valid chromosomes for the entire population (and print)
    for(int i = 0; i < GA.popSize; ++i)
    {
        random_shuffle(shuffle+1, shuffle+cities+1); // randomly re-orders the elements

        for(int j = 1; j <= cities; ++j)
        {
            genotype.pop[i][j] = shuffle[j]; // copy solution to current chromosome
        }
    }

    geneticAlgorithm(cities, map);
} // initialPopulation


/* For each chromosome in the population, evaluate its fitness.
 * Fitness is measured in total distance.
 * Distance is calculated by Euclidean distance.
 * TSP looks for the shortest path, thus the lower the fitness value is,
 * the bettter that solution (or chromosome) is.
 * The fitness value is stored in gene 0. */
void evaluateFitness(int cities, int map[][2])
{
    double distance, totalDistance;
    int city1, city2, x1, y1, x2, y2;

    for(int i = 0; i < GA.popSize; ++i)
    {
        distance = 0; totalDistance = 0; // reset distance for each chromosome
        for(int j = 1; j < cities; ++j)
        {
            city1 = (int)genotype.pop[i][j]; city2 = (int)genotype.pop[i][j+1];
            x1 = map[city1][X];              x2 = map[city2][X];
            y1 = map[city1][Y];              y2 = map[city2][Y];
            //cout << "x1: " << x1 << " y1: " << y1 << ", x2: " << x2 << " y2: " << y2 << endl;
            distance = sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ); // euclidean distance
            totalDistance += distance;
        }
        genotype.pop[i][0] = totalDistance;
    }
} // evaluateFitness


/* The Genetic Algorithm System.
 *
 * - evaluate fitness of each chromosome in population
 * for every generation
 * {
 *   while new population is not full
 *   {
 *     - select parent(1) chromosome using Tournament Selection
 *     - select parent(2) chromosome using Tournament Selection
 *     - apply crossover with probability Pc to produce two new children
 *          if crossover not applied, just copy parents
 *     - apply mutation with probability Pm to offspring
 *          if mutation not applied, no changes
 *   }
 *   - copy elite (or elites) into new population
 *   - replace old population with new population
 *   - evaluate fitness of every chromosome in the population
 * }
 */
void geneticAlgorithm(int cities, int map[][2])
{
     // allocation of multidimensional dynamic memory array
    genotype.newPop = new double *[GA.popSize];
    for(int i = 0; i < GA.popSize; i++)
	genotype.newPop[i] = new double[cities+1];

    // initialize/clear 2D-array
    for(int i = 0; i < GA.popSize; ++i)
        for(int j = 0; j < cities+1; ++j)
            genotype.newPop[i][j] = 0.0;

    double best[cities+1]; // keep track of best chromosome in long run
    best[0] = numeric_limits<double>::max();
    double sum = 0; // sum of all fitnesses to get average
    int parent1, parent2; // stores the index of each parent in the population
    float r; // r is compared with Pc and Pm
    int start; // starting index when inserting children into new population
    double prevBest = 0.0; // the fitness of the previous elite, used in Elitism

    cout << "INITIAL POPULATION:\n------------------" << endl;
    evaluateFitness(cities, map);
    printPopulation(cities);
    findElite(cities, prevBest);
    cout << "Fitness of best initial solution: " << genotype.elite[0] << endl;
    for(int i = 0; i < GA.popSize; ++i)
            sum+=genotype.pop[i][0];
        cout << "Average fitness of initial population: " << sum/GA.popSize << endl << endl;
    cout << "----------END OF INITIAL POPULATION-----------\n" << endl;

    for(int gen = 1; gen <= GA.maxGen; ++gen) // each generation produces a full population
    {
        cout << "Generation " << gen << endl;
        sum = 0;
        // insert offspring until new population is full
        // (does 1 extra iteration in case popSize is odd)
        for(int run = 0, start = 0; run < (GA.popSize/2)+1; ++run, start+=2)
        {
            // if popsize is not odd, extra run not needed
            if((GA.popSize % 2 == 0) && (run == GA.popSize/2)) continue;

            // SELECTION
            parent1 = tournamentSelection();
            parent2 = tournamentSelection();

            r = rand() / ((double) RAND_MAX); // value between 0 and 1
            cout << "iteration #" << run+1 << ", r = " << r << "\t";
            r < GA.crossRate ? cout << "yes crossover, " : cout << "no crossover, ";
            r < GA.mutRate ? cout << "yes mutation" << endl : cout << "no mutation" << endl;

            // OPTIONAL CROSSOVER
            if( r < GA.crossRate ) // perform crossover
            {
                pmCrossover(cities, parent1, parent2, start); // PMX
                //cCrossover(cities, parent1, parent2, start); // CX
            }
            else // no crossover, just copy parents
            {
                for(int i = 0; i <= cities; ++i)
                {
                    if(start < GA.popSize) // check if not out of bounds
                        genotype.newPop[start][i] = genotype.pop[parent1][i];
                    if(start+1 < GA.popSize)
                        genotype.newPop[start+1][i] = genotype.pop[parent2][i];
                }
            }

            // OPTIONAL MUTATION
            if( r < GA.mutRate ) // perform mutation
                reMutation(cities, run);
        }
        cout << "New population is full! Replaced old pop with new." << endl;

        // ELITISM -- applied once per new population
        // doesn't make a difference if applied after/before genetic operators,
        // as long as it's applied before replacing the population.
        // Elites replace the first numElite chromosomes in the full newPop
        prevBest = 0.0;
        for(int i = 0; i < GA.numElite; ++i) // repeat for n elites
        {
            findElite(cities, prevBest); // places elite into genotype.elite
            prevBest = genotype.elite[0]; // update previous best fitness

            for(int j = 0; j <= cities; ++j) // insert elite into new population
                genotype.newPop[i][j] = genotype.elite[j];
        }

        // REPLACE OLD_POP WITH NEW_POP (and clear newPop)
        for(int i = 0; i < GA.popSize; ++i)
            for(int j = 0; j <= cities; ++j)
            {
                genotype.pop[i][j] = genotype.newPop[i][j];
                genotype.newPop[i][j] = 0.0;
            }

        // EVALUATE FITNESS (of every chromosome in population)
        evaluateFitness(cities, map);

        // Print best fitness and average fitness
        prevBest = 0.0;
        findElite(cities, prevBest);
        cout << "Best fitness: " << genotype.elite[0] << endl;
        for(int i = 0; i < GA.popSize; ++i)
            sum+=genotype.pop[i][0];
        cout << "Average fitness: " << sum/GA.popSize << endl << endl;

        // Keep track of best if there is no elitism (to print best later)
        if(GA.numElite == 0)
            if(genotype.elite[0] < best[0])
            {
                for(int i = 0; i <= cities; ++i)
                    best[i] = genotype.elite[i];
            }
    } // generation

    // Print best solution fitness and its path
    if(GA.numElite == 0)
    {
        cout << "Fitness of best solution ever found: " << best[0] << endl;
        for(int i = 1; i <= cities; ++i)
            cout << "city " << best[i] << endl;
    }
    else
    {
        cout << "Fitness of best solution ever found: " << genotype.elite[0] << endl;
        for(int i = 1; i <= cities; ++i)
            cout << "city " << genotype.elite[i] << endl;
    }
        
} // GA system


/* Finds the next elite in the population and stores it for later use. */
void findElite(int cities, double prevBest)
{
   double bestFitness = numeric_limits<double>::max(); // max value
   double fitness; // fitness of the current chromosome

   for(int j = 0; j < GA.popSize; ++j) // search population
   {
        fitness = genotype.pop[j][0];
                
        if(fitness < bestFitness && fitness > prevBest) // found potential elite
        {
            bestFitness = fitness;
                    
            for(int k = 0; k <= cities; ++k) // temporarily store elite
                genotype.elite[k] = genotype.pop[j][k];
        }
   }
} // findElite


/* The selection method used is Tournament Selection.
 * Selects a chromosome that will be used to reproduce (i.e. parent).
 * Select k chromosomes randomly, from those, select the best.
 * NOTE: it's possible for the same parent to be selected twice for mating;
 * this was done on purpose because this happens in nature with certain species.
 */
int tournamentSelection(void)
{
    double bestFitness = numeric_limits<double>::max(); // max value (bad fitness)
    double fitness; // fitness of the current chromosome
    int random, bestChromosome;

    for(int i = 0; i < GA.k; ++i) // select k chromosomes randomly
    {
        random = rand() % GA.popSize; // range is 0 to popSize
        fitness = genotype.pop[random][0];
        //cout << "fitness of random chromosome " << i+1 << " = " << fitness << endl;
        if(fitness < bestFitness) // look for the best chromosome in the k-set
        {
            bestFitness = fitness;
            bestChromosome = random;
        }
    }
    //cout << "selected: " << bestFitness << endl << endl;
    return bestChromosome;
} // tournamentSelection


/* Partially Mapped Crossover (PMX) */
void pmCrossover(int cities, int parent1, int parent2, int start)
{
    /*-------print parents-------------
    for(int i = 0; i <= cities; ++i)
    {
        cout << "parent1[" << i << "] = " << genotype.pop[parent1][i] << endl;
        cout << "parent2[" << i << "] = " << genotype.pop[parent2][i] << endl;
    }
     ---------------------------------*/

    double child1[cities+1], child2[cities+1];
    for(int i = 0; i <= cities; ++i) // initialize children
    {
        child1[i] = 0.0; child2[i] = 0.0;
    }

    /* 1. Identify 2 arbitrary cut points from 1 to n (must be unique!) */
    int point1 = rand() % cities + 1;
    int point2 = rand() % cities + 1;
    while(point2 == point1) point2 = rand() % cities + 1; // make unique
    int tmp;
    if(point1 > point2) // swap
    {
        tmp = point1;
        point1 = point2;
        point2 = tmp;
    }
    //cout << "pt.A = " << point1 << ", pt.B = " << point2 << endl;

    /* 2. Crossover the genes within the cut points on the parents,
    *    over to the children. Also, keep track of the swaps. */
    // NOTE: could have probably used a multimap, but I prefer doing it this way
    map<int,int> swapC1; // eg 4 <-> 8 -- key is 8, value is 4
    map<int,int> swapC2; // eg 4 <-> 8 -- key is 4, value is 8
    for(int i = point1; i <= point2; ++i)
    {
        swapC2.insert( make_pair((int)genotype.pop[parent1][i], (int)genotype.pop[parent2][i]) );
        swapC1.insert( make_pair((int)genotype.pop[parent2][i], (int)genotype.pop[parent1][i]) );
        child1[i] = genotype.pop[parent2][i];
        child2[i] = genotype.pop[parent1][i];
    }

/*  // test: check swaps
    map<int,int>::iterator iter;
    cout << "C2" << endl;
    for( iter = swapC2.begin(); iter != swapC2.end(); ++iter )
       cout << "Key: '" << iter->first << "', Value: " << iter->second << endl;
    cout << "C1" << endl;
    for( iter = swapC1.begin(); iter != swapC1.end(); ++iter )
       cout << "Key: '" << iter->first << "', Value: " << iter->second << endl;
*/
    /* 3. Inherit the genes with no conflicts. */
    // First, inherit the genes BEFORE the 1st cut point
    for(int i = 1; i < point1; ++i) // inheritance for child1
        for(int j = point1; j <= point2; ++j)
        {
            if(genotype.pop[parent1][i] == child1[j]) break; // conflict!
            if(j == point2) child1[i] = genotype.pop[parent1][i]; // inherit
        }

    for(int i = 1; i < point1; ++i) // inheritance for child2
        for(int j = point1; j <= point2; ++j)
        {
            if(genotype.pop[parent2][i] == child2[j]) break; // conflict!
            if(j == point2) child2[i] = genotype.pop[parent2][i]; // inherit
        }
    // Second, inherit the genes AFTER the 2nd cut point
    for(int i = point2+1; i <= cities; ++i) // inheritance for child1
        for(int j = point1; j <= point2; ++j)
        {
            if(genotype.pop[parent1][i] == child1[j]) break; // conflict!
            if(j == point2) child1[i] = genotype.pop[parent1][i]; // inherit
        }

    for(int i = point2+1; i <= cities; ++i) // inheritance for child2
        for(int j = point1; j <= point2; ++j)
        {
            if(genotype.pop[parent2][i] == child2[j]) break; // conflict!
            if(j == point2) child2[i] = genotype.pop[parent2][i];
        }

    /* 4. Fill in remaining genes with help from the swap-map. */
    bool valid;
    int keyGene = 0; // gene used for checking swaps
    int missingGene = 0; // temp storage for the missing gene
    map<int,int>::iterator iter; // declare an interator to use in map

    for(int i = 1; i <= cities; ++i) // find empty spots on children
    {
        if(child1[i] == EMPTY) // fill empty spot (in C1) with a legal gene
        {
            keyGene = (int) genotype.pop[parent1][i];
            valid = false; // haven't checked if it is valid yet, so false
                
            while(!valid) // search until valid gene found
            {
                iter = swapC1.find(keyGene); // look in the swap map
                missingGene = iter->second; // first is key, second is value

                // check if gene is already in child (i.e. check if valid)
                for(int j = point1; j <= point2; ++j)
                {
                    if(missingGene == child1[j])  // conflict!
                    {
                        keyGene = missingGene; // need to check the connecting swap (eg 2<->1 connects to 1<->3)
                        break;
                    }
                    if(j == point2) // no conflict found
                    {
                        child1[i] = missingGene; // place the missing gene
                        valid = true;
                    }
                }
            }
        } // child1 complete
        if(child2[i] == EMPTY) // fill empty spot (in C2) with a legal gene
        {
            keyGene = (int) genotype.pop[parent2][i];
            valid = false; // haven't checked if it is valid yet, so false

            while(!valid) // search until valid gene found
            {
                iter = swapC2.find(keyGene); // look in the swap map
                missingGene = iter->second; // first is key, second is value

                // check if gene is already in child (i.e. check if valid)
                for(int j = point1; j <= point2; ++j)
                {
                    if(missingGene == child2[j])  // conflict!
                    {
                        keyGene = missingGene; // need to check the connecting swap (eg 2<->1 connects to 1<->3)
                        break;
                    }
                    if(j == point2) // no conflict found
                    {
                        child2[i] = missingGene; // place the missing gene
                        valid = true;
                    }
                }
            }
        } // child2 complete
    } // Offspring complete

    /*-----print children-----
    for(int i = 1; i <= cities; ++i)
        cout << "child1[" << i << "] = " << child1[i] << endl;
    cout << endl;
    for(int i = 1; i <= cities; ++i)
        cout << "child2[" << i << "] = " << child2[i] << endl;
    ---------------------------*/

    swapC1.clear();
    swapC2.clear(); // clear the maps when done (not really necessary)

    /* 5. Copy offspring into new population. */
    for(int i = 0; i <= cities; ++i)
    {
        if(start < GA.popSize) // check if not out of bounds
            genotype.newPop[start][i] = child1[i];
        if(start+1 < GA.popSize)
            genotype.newPop[start+1][i] = child2[i];
    }
    // Can also pick the best 2 chromosomes out of the 4 (i.e. P1, P2, C1, & C2)
    // however, did not implement this (GA might lack diversity)
} // pmCrossover


/* Cycle Crossover (CX).
 * Each element comes from one parent together with its position.
 * Genes selected for inheritance is based on a cycle of connecting genes.
 * Cycle starts with the first gene from the first parent. Cycle ends when
 * the last gene inherited is connected to the first gene inherited. */
void cCrossover(int cities, int parent1, int parent2, int start)
{
    double child1[cities+1], child2[cities+1];
    for(int i = 0; i <= cities; ++i) // initialize children
    {
        child1[i] = 0.0; child2[i] = 0.0;
    }

    int firstGene = (int) genotype.pop[parent1][1]; // first gene in the cycle
    int connectingGene = (int) genotype.pop[parent2][1]; // holds cycle together
    bool done = false; // done cycle?
    child1[1] = genotype.pop[parent1][1]; // Inherit first genes
    child2[1] = genotype.pop[parent2][1]; // thus loop can start at index 2 now
    while(!done)
    {
        for(int i = 2; i <= cities; ++i)  // look for genes in the cycle
        {
            if(connectingGene == firstGene)
            {
             done = true;
             break; // break out of for loop
            }
            if((int)genotype.pop[parent1][i] == connectingGene) // a connection
            {
             child1[i] = genotype.pop[parent1][i]; // inherit on same position
             child2[i] = genotype.pop[parent2][i];
             connectingGene = (int) genotype.pop[parent2][i];
            }
        }
    }

    for(int i = 1; i <= cities; ++i) // Crossover with same position
    {
        if(child1[i] == EMPTY) // can also check if C2 is empty, doesn't matter
        {
            child1[i] = genotype.pop[parent2][i];
            child2[i] = genotype.pop[parent1][i];
        }
    }

    for(int i = 0; i <= cities; ++i) // Copy offspring into new population
    {
        if(start < GA.popSize) // check if not out of bounds
            genotype.newPop[start][i] = child1[i];
        if(start+1 < GA.popSize)
            genotype.newPop[start+1][i] = child2[i];
    }

    /*-------print parents-------------
    for(int i = 0; i <= cities; ++i)
        cout << "parent1[" << i << "] = " << genotype.pop[parent1][i] << endl;
    cout << endl;
    for(int i = 0; i <= cities; ++i)
        cout << "parent2[" << i << "] = " << genotype.pop[parent2][i] << endl;
    cout << endl;
     ---------------------------------*/
    /*-----print children-----
    for(int i = 1; i <= cities; ++i)
        cout << "child1[" << i << "] = " << child1[i] << endl;
    cout << endl;
    for(int i = 1; i <= cities; ++i)
        cout << "child2[" << i << "] = " << child2[i] << endl;
    cout << endl;
    ---------------------------*/
} // cCrossover


/* Reciprocal Exchange Mutation (REM).
 * Swaps two arbitrary genes in the offspring. */
void reMutation(int cities, int run)
{
    // choose two arbitrary genes (must be unique)
    int gene1 = rand() % cities + 1;
    int gene2 = rand() % cities + 1;
    while(gene2 == gene1) gene2 = rand() % cities + 1; // make unique

    // search for the last two offspring
    int i, tmp;
    bool found = false; // found the offspring (by finding an empty spot)

    for(i = 0; i < GA.popSize; ++i)
    {
        if(genotype.newPop[i][1] == EMPTY) // looks for an empty spot in pop (offspring will be right before)
        {
            found = true;

            // perform REM on first child
            tmp = (int) genotype.newPop[i-1][gene1];
            genotype.newPop[i-1][gene1] = genotype.newPop[i-1][gene2];
            genotype.newPop[i-1][gene2] = tmp;

            if(i != GA.popSize-1) // if i is not the last empty spot, can mutate the 2nd child
            {
                tmp = (int) genotype.newPop[i-2][gene1];
                genotype.newPop[i-2][gene1] = genotype.newPop[i-2][gene2];
                genotype.newPop[i-2][gene2] = tmp;
            }
            break; // empty spot found, discontinue search
        }
    }

    if(!found) // if it couldn't find an empty spot, offspring are two last spots
    {
        // REM on first child
        tmp = (int) genotype.newPop[GA.popSize-1][gene1];
        genotype.newPop[GA.popSize-1][gene1] = genotype.newPop[GA.popSize-1][gene2];
        genotype.newPop[GA.popSize-1][gene2] = tmp;

        // REM on second child
        tmp = (int) genotype.newPop[GA.popSize-2][gene1];
        genotype.newPop[GA.popSize-2][gene1] = genotype.newPop[GA.popSize-2][gene2];
        genotype.newPop[GA.popSize-2][gene2] = tmp;
    }
} //reMutation


/* Main: deal with user input and start the program. */
int main(int argc, char** argv)
{
    // initialize random number seed. system time makes it unpredictable.
    srand ( time(NULL) ); /* COMMENT THIS LINE IF YOU ARE TESTING/DEBUGGING */

    cout << "\nThis program is an implementation of a Genetic Algorithm (GA)"
            " system for the Traveling Salesman Problem (TSP).\n" << endl;

    // check for errors in parameter input and set parameters if no error
    if(EOF == sscanf(argv[1], "%d", &GA.popSize))
    {
        cout << "popSize error!" << endl;
        exit(0);
    }
    if(EOF == sscanf(argv[2], "%d", &GA.maxGen))
    {
        cout << "maxGen error!" << endl;
        exit(0);
    }
    if(EOF == sscanf(argv[3], "%f", &GA.crossRate))
    {
        cout << "crossRate error!" << endl;
        exit(0);
    }
    if(EOF == sscanf(argv[4], "%f", &GA.mutRate))
    {
        cout << "mutRate error!" << endl;
        exit(0);
    }
    if(EOF == sscanf(argv[5], "%d", &GA.numElite))
    {
        cout << "numElite error!" << endl;
        exit(0);
    }
    if(EOF == sscanf(argv[6], "%d", &GA.k))
    {
        cout << "k error!" << endl;
        exit(0);
    }

    // print user input values and check for errors
    cout << "Population Size = " << GA.popSize << endl;
    cout << "Maximum Generations = " << GA.maxGen << endl;
    cout << "Crossover Rate = " << showpoint << GA.crossRate << endl;
    if(GA.crossRate < 0.0 || GA.crossRate > 1.0)
    {
        cout << "\nError: crossover rate needs to be between 0% and 100%!\n" << endl;
        exit(0);
    }
    cout << "Mutation Rate = " << GA.mutRate << noshowpoint << endl;
    if(GA.mutRate < 0.0 || GA.mutRate > 1.0)
    {
        cout << "\nError: mutation rate needs to be between 0% and 100%!\n" << endl;
        exit(0);
    }
    cout << "Number of Elites = " << GA.numElite << endl;
    if(GA.numElite >= GA.popSize)
    {
        cout << "\nError: population size needs to be larger than amount of "
                "elites!\n" << endl;
        exit(0);
    }
    cout << "Tournament Selection k = " << GA.k << endl << endl;
    if(GA.k < 2 || GA.k > 4)
    {
        cout << "Error: k needs to be between 2 and 4!\n" << endl;
        exit(0);
    }

    readData();

    return (EXIT_SUCCESS);
}

