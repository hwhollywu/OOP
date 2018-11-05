// ----------------------------------------------------------
// Simulator class for Problem Set 5.			simulator.cpp
// Author: Hao Wu 
// Date: Nov 3, 2018.
// -----------------------------------------------------------

#include "simulator.hpp"

//------------------------------------------------------------
// Constructor
Simulator::
Simulator(Population& p){
	numRounds = 0;
	ppl = p;
};  

// ----------------------------------------------------------
//  This function returns a uniformly-distributed random 
// integer in the range [0, ... n-1].
int uRandom( int n ) {
  long int usefulMax = RAND_MAX - ((RAND_MAX - n) +1)%n;
  long int r;
  do { r = random(); }
  while ( r > usefulMax );
  return r % n;
}

//-----------------------------------------------------------------------
// Prints the result of simulation
std::ostream& Simulator::
print(ostream& out) const {
	out << "Results of simulation:" << endl;
	out << "      Rounds:  "<< numRounds << endl;
	out << "   Consensus:      "<< consensusValue() << endl;
	return out;
}

// ----------------------------------------------------------
//  This function runs the simulation for as many rounds as 
//  it takes to reach consensus. Return the consensus value.
void Simulator::
run(){
	// keep taking random communication rounds 
	while(!ppl.consensusReached()){
		// select a random pair of agents as sender and receiver 
		int n = ppl->numAgents;
		int sender = uRandom(n);
		int receiver = uRandom(n - 1);
		//  keep sender and receiver distinct
		if (receiver >= sender){
			receiver += 1;
		}
		ppl.sendMessage(sender,receiver);
		// increment number of rounds
		numRounds += 1;
	}
	// return the consensus value
	return ppl.consensusValue();
}
