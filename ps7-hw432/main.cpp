// ----------------------------------------------------------
// Main Program for Problem Set 7.					main.cpp
// Author: Hao Wu 
// Date: Dec 7, 2018.
// -----------------------------------------------------------

#include "tools.hpp"
#include "simulator.hpp"

void run(int argc, char* argv[]);

// ----------------------------------------------------------
// Main function. Print a header, execute a function, 
// and print a termination message. 

int main(int argc, char* argv[]) {
	banner();
	// only pass the right number of arguments 
	if (argc == 6 || argc == 7){
		run(argc, argv);
	}else{
		fatal("Wrong number of command line arguments!");
	}
	bye();
}

// ----------------------------------------------------------
//  This function instantiates a Simulator object 
// and simulates the blockchain consensus problem with 3-way agents.

void run(int argc, char* argv[]) {
	int numAgents = atoi(argv[1]);
	int maxRounds = atoi(argv[2]);
	double probNak = atof(argv[3]);
	double probFickle = atof(argv[4]);
	double probExtend = atof(argv[5]);
	double probCrowd = 1.0 - probNak - probFickle;
	unsigned int seed;
	cout << "Welcome to Consensus Simulator!" << endl;
	/*
	cout << "Please give the following inputs: " << endl;
	cout << "numAgents: the total number of agents " << endl;
	cout << "maxRounds: the total number of simulation rounds to perform. " << endl;
	cout << "probNak: the probability of selecting a Nakamoto agent when building the population." << endl;
	cout << "probFickle: the probability of selecting a Fickle agent when building the population." << endl;
	cout << "probExtend: the probability that the simulator chooses to simulate an extend() operation rather than a sendMessage() operation." << endl;
	cout << "[seed]: optional seed for the random number generator" << endl;
	*/

	// check input
	if (probNak > 1 || probNak < 0 || probFickle > 1 || probFickle < 0 || probExtend > 1 || probExtend < 0){
		fatal("Wrong input! probNak, probFickle and probExtend should be in range [0,1].");
	}
	if (probCrowd > 1 || probCrowd < 0){
		fatal("Wrong input! The probability of selecting a Crowd agent should be in range [0,1].");
	}
	// check if seed is provided 
	if (argc == 6){
		seed = time(0);
	}else {
		seed = atoi(argv[6]);
	}
	// set the seed for random function
	srand(seed);
	// print initial parameters
    cout << "Using seed: " << seed << endl;
    cout << "   numAgents:	 " << numAgents << endl;
    cout << "  maxRounds:    " << maxRounds << endl;
    cout << "     probNak:    " << probNak << endl;
    cout << "  probFickle:    " << probFickle << endl;
    cout << "  probExtend:    " << probExtend << endl;
    // Declare and initilize a population class
    Population ppl = Population(numAgents,probNak,probFickle,probExtend);
    cout << ppl;  // print population stats
	// Declare and initialize the Simulator class.
    Simulator s = Simulator(ppl,maxRounds,probExtend);  
    // Execute the simulator function.
    s.run();    
}


