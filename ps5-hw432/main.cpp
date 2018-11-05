// ----------------------------------------------------------
// Main Program for Problem Set 5.					main.cpp
// Author: Hao Wu 
// Date: Nov 3, 2018.
// -----------------------------------------------------------

#include "tools.hpp"
#include "simulator.hpp"

void run(int argc, char* argv[]);

// ----------------------------------------------------------
// Main function. Print a header, execute a function, 
// and print a termination message. 

int main(int argc, char* argv[]) {
	banner();
	// only pass the right number of arguments (3 or 4)
	if (argc == 4 || argc == 5){
		run(argc, argv);
	}else{
		fatal("Wrong number of command line arguments!");
	}
	bye();
}

// ----------------------------------------------------------
//  This function instantiates a Simulator object 
// and simulates the consensus problem with fickle players.

void run(int argc, char* argv[]) {
	int numAgents = atoi(argv[1]);
	double probFickle = atoi(argv[2]);
	double probOne = atoi(argv[3]);
	unsigned int seed;
	cout << "Welcome to Consensus Simulator!" << endl;
	// check input
	if (probFickle >= 1 || probFickle < 0 || probOne >= 1 || probOne < 0){
		fatal("Wrong input! probFickle and probOne should be in range [0,1).");
	}
	// check if seed is provided 
	if (argc == 4){
		seed = time(0);
	}else {
		seed = atoi(argv[4]);
	}
	// print initial parameters
    cout << "Using seed: " << seed << endl;
    cout << "   numAgents:" << numAgents << endl;
    cout << "  probFickle:" << probFickle << endl;
    cout << "     probOne:" << probOne << endl;
    // Declare and initilize a population class
    Population ppl = Population(numAgents,probFickle, probOne, seed);
    cout << ppl << endl;  // print population stats
	// Declare and initialize the Simulator class.
    Simulator s = Simulator(ppl);  
    // Execute the simulator function.
    s.run();    
    cout << s << endl; // print results of simulation
}


