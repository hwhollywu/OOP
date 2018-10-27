// ----------------------------------------------------------
// Main Program for Problem Set 4.					main.cpp
// Author: Hao Wu 
// Date: October 26, 2018.
// -----------------------------------------------------------

#include "tools.hpp"
#include "simulator.hpp"


void run(char* argv[]);

// ----------------------------------------------------------
// Main function. Print a header, execute a function, 
// and print a termination message. 

int main(int argc, char* argv[]) {
	banner();
	// only pass the right number of arguments (2 or 3)
	if (argc == 2 || argc == 3){
		run(argv);
	}else{
		fatal("Wrong number of command line arguments!");
	}
	bye();
}

// ----------------------------------------------------------
//  This function instantiates a Simulator object 
// and simulates the consensus problem with fickle players.

void run(char* argv[]) {
	int numAgents = atoi(argv[1]);
	int numOne = atoi(argv[2]);
	unsigned int seed = atoi(argv[3]);
	// check if numAgents > numOne
	if (numAgents < numOne){
		fatal("numAgents < numOne! Please provide valid inputs.");
	}
	int rounds = 0;
	// Declare and initialize the Simulator class.
    Simulator s = Simulator(numAgents,numOne,seed);  
    // Execute the simulator function.
    int consensusValue = s.run(rounds);    
    // print output
    cout << numAgents << numOne << seed << rounds << consensusValue << endl;
}


