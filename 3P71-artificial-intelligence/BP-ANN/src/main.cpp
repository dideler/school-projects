/* 
 * File:   main.cpp
 * Author: Dennis Ideler <di07ty@brocku.ca> [4134466]
 *
 * Created on November 28, 2009, 5:08 PM
 */

#include <cstdlib>
#include <ctime>    // time used as seed for random number generator
#include <iostream>
#include <fstream>
#include <string>
#include <cmath> // for exp (i.e. the base-e exponential function of x)
using namespace std;


struct PE // Neurode, Node, Neuron, Unit, etc.
{
    double value;           // sum of inputs; input value
    //double bias;          // bias value
    double error;           // sum of error
    double thres;           // threshold value
    double thresChange;     // threshold change
    double * weight;        // connection weights vector for the node
    double * weightChange;  // weight change

    double sigmoid(double x)
    {
        return 1 / (1 + exp(-x /* + bias */));
    }

    double derivative(void)
    {
        return value * (1 - value);
    }
};


struct ANN // Artificial Neural Net
{
    int numInput;   // number of input nodes
    int numHidden;  // number of hidden nodes
    int numOutput;  // number of output nodes
    //int limit;    // iteration limit to reset training if stuck in local min
    PE * Fa;        // (nodes in) input layer
    PE * Fb;        // (nodes in) hidden layer
    PE * Fc;        // (nodes in) output layer
    float learnRate;// learning rate
    float momentum; // momentum
    unsigned int randSeed;  // seed for random number generator
    int epochs;     // number of epochs
    int numPatterns;// number of input patterns or stimulus
    int bits;       // number of bits in a pattern

    ANN() // default constructor (initialize the ANN)
    {
        numInput = 4;
        numHidden = 4;
        numOutput = 1;
        //limit = 2000; // use if termination by error value (not by max epochs)
        learnRate = 0.5;
        momentum = 0.9;
        randSeed = time(NULL);
        srand(randSeed); // comment this line during testing
        epochs = 200000;
        numPatterns = 16;
        bits = 4;
        float lower = -0.5, upper = 0.5, range = (upper - lower); // or -1, 1
        float t_low = -0.125, t_high = 0.125, t_range = (t_high - t_low);

        /* Print some params */
        cout << "\n==Parameters==\nNumber of input neurons: " << numInput
                << "\nNumber of hidden neurons (1 hidden layer): " << numHidden
                << "\nNumber of output neurons: " << numOutput
                << "\nLearning rate: " << learnRate
                << "\nMomentum: " << momentum
                << "\nWeight range: [" << lower << ", " << upper << "]"
                << "\nThreshold range: [" << t_low << ", " << t_high << "]"
                << "\nNumber of epochs: " << epochs
                << "\nNumber of stimulus: " << numPatterns
                << "\nNumber of bits per pattern: " << bits
                << "\nRandom number seed: " << randSeed << endl;

        /* Set up layers; layer implemented as array of PEs */
        Fa = new PE[numInput];
        Fb = new PE[numHidden];
        Fc = new PE[numOutput];

        /* Initialize weight vectors. Only PEs in Fb and Fc have connection
         * weights (could have also done Fa and Fb, doesn't really matter).
         * Actually, the weights shouldn't be connected to a single layer, since
         * they are between the layers. The weights should actually be in a
         * separate class, but doing it this way is more simple. */
        for(int i = 0; i < numInput; ++i)
            Fb[i].weight = new double[numInput]; // weights from input to hidden
        for(int i = 0; i < numHidden; ++i)
            Fc[i].weight = new double[numHidden]; // weights from hidden to output
        
        /* Initialize connection weights in the specified range for every node
         *  in the Fb layer. */
        cout << "\n==Initializing weights==\n"
                "Connection weights from Fa -> Fb" << endl;
        for(int i = 0; i < numHidden; ++i)
        {
            cout << "\nHidden layer (Fb) neuron " << i+1 << endl;
            for(int j = 0; j < numInput; ++j)
            {
                // The commented line is range -1 to 1
                //Fb[i].weight[j] = ((double) rand() / RAND_MAX) * 2 - 1;
                Fb[i].weight[j] = lower + (double) (range * rand() / (RAND_MAX + 1.0));
                cout << "connection weight from Input layer (Fa) neuron "
                        << j+1 << " = " << Fb[i].weight[j] << endl;
            }
        }

        /* Initialize connection weights in the specified range for every node
         *  in the Fc layer. */
        cout << "\nConnection weights from Fb -> Fc" << endl;
        for(int i = 0; i < numOutput; ++i)
        {
            cout << "\nOutput layer (Fc) neuron " << i+1 << endl;
            for(int j = 0; j < numHidden; ++j)
            {
                //Fc[i].weight[j] = ((double) rand() / RAND_MAX) * 2 - 1;
                Fc[i].weight[j] = lower + (double) (range * rand() / (RAND_MAX + 1.0));
                cout << "connection weight from Hidden layer (Fb) neuron "
                        << j+1 << " = " << Fc[i].weight[j] << endl;
            }
        }

        /* Initialize weight change to 0 for PEs in Fb and Fc*/
        for(int i = 0; i < numHidden; ++i)
        {
            Fb[i].weightChange = new double[numInput]; // weights from input to hidden
            for(int j = 0; j < numInput; ++j)
                Fb[i].weightChange[j] = 0.0;
        }
        for(int i = 0; i < numOutput; ++i)
        {
            Fc[i].weightChange = new double[numHidden]; // weights from hidden to output
            for(int j = 0; j < numHidden; ++j)
                Fb[i].weightChange[j] = 0.0;
        }

        /* Initialize threshold values for every PE in each layer.
         * (All initializations could have been done in the same loops, but I 
         * didn't do that to make it clearer what's going on in the code.) */
        cout << "\n==Initializing threshold values==\nInput layer (Fa)" << endl;
        for(int i = 0; i < numInput; ++i)
        {
            Fa[i].thres = t_low + (double) (t_range * rand() / (RAND_MAX + 1.0));
            Fa[i].thresChange = 0.0;
            cout << "threshold of neuron " << i+1 << " = " << Fa[i].thres << endl;
        }
        cout << "\nHidden layer (Fb)" << endl;
        for(int i = 0; i < numHidden; ++i)
        {
            Fb[i].thres = t_low + (double) (t_range * rand() / (RAND_MAX + 1.0));
            Fb[i].thresChange = 0.0;
            cout << "threshold of neuron " << i+1 << " = " << Fb[i].thres << endl;
        }
        cout << "\nOutput layer (Fc)" << endl;
        for(int i = 0; i < numOutput; ++i)
        {
            Fc[i].thres = t_low + (double) (t_range * rand() / (RAND_MAX + 1.0));
            Fc[i].thresChange = 0.0;
            cout << "threshold of neuron " << i+1 << " = " << Fc[i].thres << endl;
        }

    } // constructor
} net;


struct Pattern // the stimulus (aka input patterns)
{
    int * input; // bit data
    int output;  // expected output of pattern
} * patterns;


/* Prototypes */
void loadPatterns(void); // load patterns (from file)
//void saveANN(void); // save the weights (to file)
//void loadANN(void); // load the weights (from file)
void trainANN(void);// uses training set
void testANN(void); // uses testing set


/* Test the network on the trained data by forwardpropagation. */
void testANN()
{
    cout << "\n==Test Results==" << endl;
    
    for(int iter = 0; iter < net.numPatterns; ++iter)
    {
        cout << "\nStimulus: ";
        for(int i = 0; i < net.bits; ++i)
        {
            net.Fa[i].value = patterns[iter].input[i];
            cout << patterns[iter].input[i];
        } cout << endl;

        for(int j = 0; j < net.numHidden; ++j)
        {
            double sum = 0.0;
            for(int k = 0; k < net.numInput; ++k)
                sum += net.Fb[j].weight[k] * net.Fa[k].value;
            
            net.Fb[j].value = net.Fb[j].sigmoid(sum /*+ net.Fb[j].thres*/);
            cout << "Fb node " << j+1 << " has activation " << sum << "\t";
            cout << "its response is " << net.Fb[j].value << endl;
        }

        for(int i = 0; i < net.numOutput; ++i)
        {
            double sum = 0.0;
            for(int j = 0; j < net.numHidden; ++j)
                sum += net.Fc[i].weight[j] * net.Fb[j].value;

            net.Fc[i].value = net.Fc[i].sigmoid(sum /*+ net.Fc[i].thres*/);
            cout << "Fc node " << i+1 << " has activation " << sum << "\t";
            cout << "its response is " << net.Fc[i].value << endl;
        }
    }
}


/* The backpropagation algorithm consists of two phases:
 *
 * In the first phase, a forward flow of activation is generated from the input
 * layer to the output layer via the hidden layer. Each unit in the hidden lay-
 * er computes its activation as a weighted sum of its inputs and transforms it
 * into its response using its transfer function (i.e. sigmoid function).
 * The response of the hidden layer is the input of the output layer.
 *
 * In the second phase, the error term (i.e. difference between computed output
 * and desired output) is computed. The error term is then transformed into an
 * error signal which takes into account the derivative of the cell activations.
 * The error signal is then backpropagated through the network, layer by layer.
 * After the connection weights have been used to backpropagate the error, they
 * are adjusted so as to minimize the mean-square error between the network
 * output and the desired output. */
void trainANN() // all standard output is current disabled (i.e. commented)
{
    for(int epoch = 0; epoch < net.epochs; ++epoch)
    {
        //cout << "\nEpoch #" << epoch+1 << endl;
        for(int iter = 0; iter < net.numPatterns; ++iter)
        {
            //cout << "\nIteration #" << iter+1 << "\tStimulus: ";
            /** Phase 1: forwardpropagation (i.e. the forward pass) **/

            /* Present the current stimulus to the input layer (Fa) units.
             * That is, transfer the ak values to the Fa PEs. */
            for(int i = 0; i < net.bits; ++i)
            {
                net.Fa[i].value = patterns[iter].input[i];
                //cout << patterns[iter].input[i];
            } //cout << endl;

            /* Activate the neurons in the hidden layer (Fb).
             * That is, calculate the new Fb PE values. */
            for(int j = 0; j < net.numHidden; ++j)
            {
                double sum = 0.0; // the weighted sum of a neuron's inputs
                for(int k = 0; k < net.numInput; ++k)
                {
                    /* Each unit first computes a weighted sum of its inputs */
                    sum += net.Fb[j].weight[k] * net.Fa[k].value;
                }
                /* Then it applies an activation function (i.e. sigmoid) to this
                 * sum to derive the output, which is the new Fb PE value.
                 * Note that threshold is added to the sum before it goes
                 * through the sigmoid function */
                net.Fb[j].value = net.Fb[j].sigmoid(sum /*+ net.Fb[j].thres*/);
                //cout << "Fb node " << j+1 << " has activation " << sum << "\t";
                //cout << "its response is " << net.Fb[j].value << endl;
            }

            /* Activate the neuron in the output layer (Fc).
             * That is, calculate the new Fc PE value. */
            for(int i = 0; i < net.numOutput; ++i)
            {
                double sum = 0.0;
                for(int j = 0; j < net.numHidden; ++j)
                {
                    sum += net.Fc[i].weight[j] * net.Fb[j].value;
                }
                net.Fc[i].value = net.Fc[i].sigmoid(sum /*+ net.Fc[i].thres*/);
                //cout << "Fc node " << i+1 << " has activation " << sum << "\t";
                //cout << "its response is " << net.Fc[i].value << endl;
            }

            /** Phase 2: backpropagation (i.e. the learning part) **/

            for(int i = 0; i < net.numOutput; ++i)
            {
                /* Compute the error (e) by the supervisor as the difference
                 * between the computed response (t_hat) and the expected
                 * response (t):  e = t - t_hat
                 */
                net.Fc[i].error = patterns[iter].output - net.Fc[i].value;

                /* Compute the error signal (delta):
                 *
                 * First compute the derivative of the output unit responses:
                 *  f'(a) = t_hat * (1 - t_hat)
                 *
                 * Then the error signal is computed as the product of this
                 * derivative and the error:
                 *  delta = f'(a) * e = t_hat * (1- t_hat) * (t - t_hat)
                 */
                net.Fc[i].error = net.Fc[i].derivative() * net.Fc[i].error;
                //FIXME should the error signal be stored in the value instead?
            }

            /* The output units will now backpropagate this error signal to the
             * hidden units:
             * 
             * First, the amount of output error attributable to each hidden
             * unit is estimated by multiplying the error signal of each output
             * unit by the weights which connect the hidden layer to the output
             * layer.
             * Each hidden unit then sums its estimated error received from this
             * backpropagation ("blame" or "responsibility"). This hidden unit
             * error is (formally) denoted as e_hat.
             */
            for(int j = 0; j < net.numHidden; ++j)
            {
                double sum = 0.0;
                for(int i = 0; i < net.numOutput; ++i)
                {
                    sum += net.Fc[i].weight[j] * net.Fc[i].error;
                }
                net.Fb[j].error = sum;
            }

            /* The error signal of the hidden units is then computed similarly
             * to the error signal of the output units, except that the error
             * given by the supervisor is replaced by the estimation of the
             * hidden layer error.
             *
             * First, the derivative of the hidden unit responses is computed:
             *  f'(b) = h * (1 - h)
             *
             * Then the error signal is given by:
             *  delta_hidden = f'(b) * e_hat
             *
             * Momentum and a learning rate are optional, but this program uses
             * them, so they are incorporated into the forumala.
             */   
            for(int k = 0; k < net.numInput; ++k)
            {
                for(int j = 0; j < net.numHidden; ++j)
                {
                    net.Fb[j].weightChange[k] = (net.Fb[j].weightChange[k] *
                            net.momentum) + (net.learnRate * net.Fa[k].value *
                            net.Fb[j].error * net.Fb[j].derivative());

                    net.Fb[j].weight[k] += net.Fb[j].weightChange[k];
                }
            }

            /* Once the error signal is backpropagated to the hidden layer,
             * the synaptic weights are corrected. */
            for(int i = 0; i < net.numOutput; ++i)
            {
                for(int j = 0; j < net.numHidden; ++j)
                {
                    net.Fc[i].weightChange[j] = (net.Fc[i].weightChange[j] *
                            net.momentum) + (net.learnRate * net.Fc[i].value *
                            net.Fb[j].error * net.Fb[j].derivative());

                    net.Fc[i].weight[j] += net.Fc[i].weightChange[j];

                    /* Optional: update bias (make sure bias was init'ed) */
                    //net.Fb[j].bias += net.Fb[j].error * net.Fb[j].derivative()
                    //    * net.learnRate;
                }

                /* Optional: update threshold */
                net.Fc[i].thresChange += net.learnRate * net.Fc[i].error *
                    net.Fc[i].derivative();

                net.Fc[i].thres += net.Fc[i].thresChange;
            }
        }
    }
}


/* Load patterns plus their output from file. */
void loadPatterns()
{
    patterns = new Pattern[net.numPatterns];
    string pattern; // temp storage

    cout << "\n==Loading patterns==" << endl;
    for(int i = 0; i < net.numPatterns; ++i)
    {
        patterns[i].input = new int[net.bits]; // stimuli consists of 4 bits
        cin >> pattern;
        
        for(int j = 0; j < pattern.size(); ++j) // parse pattern
            patterns[i].input[j] = ((int) pattern.at(j)) - 48; // subtract ASCII value

        cin >> patterns[i].output;
    }

    /* Print patterns and its associated output */
    for(int i = 0; i < net.numPatterns; ++i)
    {
        cout << "pattern " << i+1 << ":\t";
        for(int j = 0; j < pattern.size(); ++j)
        {
            cout << patterns[i].input[j];
        }
        cout << "\toutput = " << patterns[i].output << endl;
    }
}


/* BP-ANN: with 4 input nodes, 4 hidden nodes, and 1 output node.
 * Checking the even parity bit.
 */
int main(int argc, char** argv)
{
    loadPatterns();
    trainANN(); // uses 100% of the patterns as training data
    testANN(); // uses 100% of the patterns as testing data
    return (EXIT_SUCCESS);
}

