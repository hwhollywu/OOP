// ----------------------------------------------------------
// Main Program for Problem Set 4.					main.cpp
// Author: Hao Wu 
// Date: October 26, 2018.
// -----------------------------------------------------------

#include "tools.hpp"
#include "simulator.hpp"


void run();

// ----------------------------------------------------------
// Main function. Print a header, execute a function, 
// and print a termination message. 

int main(int argc, char* argv[]) {
	banner();
	// only pass the right number of arguments (2 or 3)
	if (argc == 2){
		run(argv[1], argv[2], time[0]);
	}else if (argc == 3){
		run(argv[1], argv[2], argv[3]);
	}else{
		fatal("Wrong number of command line arguments!");
	}
	run();
	bye();
}

// ----------------------------------------------------------
//  This function instantiates a Simulator object 
// and call the Game object’s play() function.

void run(int numAgents, int numOne, unsigned int seed) {
	// check if numAgents > numOne
	if (numAgents < numOne){
		fatal("numAgents < numOne! Please provide valid inputs.")
	}
	int rounds = 0;
	// Declare and initialize the Simulator class.
    Simulator(numAgents,numOne,seed) s;  
    // Execute the simulator function.
    int consensusValue = s.run(rounds);    
    // print output
    cout << "numAgents: "<< numAgents << "numOne: "<< numOne 
    << "seed: "<< seed << "numRounds: "<< rounds
    << "consensusValue: "<< consensusValue  << endl;
}


